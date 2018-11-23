#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000

int V;
vector<vii> adjList;

vi dijkstras(int s){
	vi dist(V,INF);
	priority_queue<ii,vii,greater<ii> > q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty()) {
		ii u = q.top(); q.pop();
		if(u.first > dist[u.second]) {
			continue;
		} 
		for(int i = 0; i < (int)adjList[u.second].size(); i++) {
			ii v = adjList[u.second][i];
			if(dist[v.first] > dist[u.second] + v.second) {
				dist[v.first] = dist[u.second] + v.second;
			}
		}
	}
	return dist;
}

