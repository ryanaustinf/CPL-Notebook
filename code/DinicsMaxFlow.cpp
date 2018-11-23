#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define MAX_N 1000
#define INF 1000000000

typedef vector<int> vi;

class Edge {
	public:
	int u, v, cap, rem;
	Edge(int _u, int _v, int _cap) : u(_u), v(_v), cap(_cap), rem(_cap) {}
};

int V, f, s, t;
vi p;
vector<vector<Edge *> > adjList;
Edge *res[MAX_N][MAX_N];

void augment(int v, int minEdge) {
	// printf("augmenting %d\n",v);
	if(v == s) {
		f = minEdge;
	} else if(p[v] != -1) {
		augment(p[v],min(minEdge,res[p[v]][v]->rem));
		res[p[v]][v]->rem -= f;
		res[v][p[v]]->rem += f;
	}
}

int dinicsMaxFlow(int source, int sink) {
	int mf = 0;
	s = source;
	t = sink;
	bool hasFlow = true;
	while(hasFlow) {
		vi dist(V,INF);
		queue<int> q;
		q.push(s);
		dist[s] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			// printf("exploring %d\n",u);
			if(u == t) {
				break;
			} else {
				for(int i = 0; i < (int)adjList[u].size(); i++) {
					Edge *e = adjList[u][i];
					if(e->rem > 0 && dist[e->v] == INF){
						dist[e->v] = dist[u] + 1;
						q.push(e->v);
					}
				}
			}
		}
		hasFlow = false;
		while(true) {
			f = 0;
			bitset<MAX_N> visited;
			q = queue<int>();
			q.push(s);
			p.assign(V,-1);
			visited.set(s);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if(u == t) {
					break;
				} else {
					for(int i = 0; i < (int)adjList[u].size(); i++) {
						Edge *e = adjList[u][i];
						if(e->rem > 0 && !visited.test(e->v) && dist[e->v] == dist[u] + 1){
							p[e->v] = u;
							visited.set(e->v);
							q.push(e->v);
						}
					}
				}
			}
			augment(t,INF);
			if( f == 0) {
				break;
			}
			mf += f;
			hasFlow = true;
		}
	}
	return mf;
}

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int main() {
	V = 7;
	adjList.assign(V,vector<Edge*>());

	/**
	 * This is a sample graph. 
	 */
	vector<iii> edges;
	edges.push_back(iii(0,ii(1,10)));
	edges.push_back(iii(0,ii(4,10)));
	edges.push_back(iii(1,ii(2,20)));
	edges.push_back(iii(2,ii(3,10)));
	edges.push_back(iii(4,ii(1,10)));
	edges.push_back(iii(2,ii(5,5)));
	edges.push_back(iii(3,ii(6,10)));
	edges.push_back(iii(5,ii(6,10)));

	for(int i = 0; i < (int)edges.size(); i++) {
		/**
		 * This is how to add an edge.
		 */
		iii cur = edges[i];
		Edge *e = new Edge(cur.first,cur.second.first,cur.second.second);
		Edge *eRev = new Edge(cur.second.first,cur.first,0);
		adjList[cur.first].push_back(e);
		adjList[cur.second.first].push_back(eRev);
		res[cur.first][cur.second.first] = e;
		res[cur.second.first][cur.first] = eRev;
	}
	printf("maxflow: %d\n",dinicsMaxFlow(0,6));
	return 0;
}