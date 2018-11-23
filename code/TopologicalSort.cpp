#include <vector>
#include <utility>
#include <queue>
#include <bitset>

using namespace std;

#define UNVISITED 1
#define VISITED 2
#define MAX_N 1000

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int V;
vector<vii> adjList;
vi dfs_num;

void dfs(int u,vi &toposort){
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int)adjList[u].size(); i++) {
		ii v = adjList[u][i];
		if(dfs_num[v.first] == UNVISITED) {
			dfs(v.first,toposort);
		}
	}
	toposort.push_back(u);
}

void printToposortTarjan() {
	vi toposort;
	for(int i = 0; i < V; i++) {
		if(dfs_num[i] == UNVISITED) {
			dfs(i,toposort);
		}
	}
	printf("Toposort:");
	for(int i = (int)toposort.size() - 1; i >= 0; i--){
		printf(" %d",toposort[i]);
	}
	printf("\n");
}

void printToposortKahns() {
	priority_queue<int,vi,greater<int> > q;
	vi degree(V,0);
	for(int u = 0; u < V; u++) {
		for(int i = 0; i < (int)adjList[u].size(); i++) {
			degree[adjList[u][i].first]++;
		}
	}
	for(int u = 0; u < V; u++) {
		if(degree[u] == 0) {
			q.push(u);
		}
	}

	vi toposort;
	while(!q.empty()) {
		int u = q.top(); q.pop();
		toposort.push_back(u);
		for(int i = 0; i < (int)adjList[u].size(); i++) {
			ii v = adjList[u][i];
			degree[v.first]--;
			if(degree[v.first] == 0) {
				q.push(v.first);
			}
		}
	}

	printf("Toposort:");
	for(int i = 0; i < (int)toposort.size(); i++){
		printf(" %d",toposort[i]);
	}
	printf("\n");
}

vi globalToposort;
bitset<MAX_N> used;
int ctr = 1;

void recurse(int cur,vi &degree) {
	if(cur == V){
		printf("Toposort #%d:",ctr++);
		for(int i = 0; i < (int)globalToposort.size(); i++){
			printf(" %d",globalToposort[i]);
		}
		printf("\n");
	} else {
		for(int u = 0; u < V; u++) {
			// printf("cur = %d\tdegree[%d] = %d\n",cur,u,degree[u]);
			if(!used.test(u) && degree[u] == 0) {
				globalToposort.push_back(u);
				for(int i = 0; i < (int)adjList[u].size(); i++) {
					degree[adjList[u][i].first]--;
				}
				used.set(u);
				recurse(cur + 1,degree);
				globalToposort.pop_back();
				for(int i = 0; i < (int)adjList[u].size(); i++) {
					degree[adjList[u][i].first]++;
				}
				used.reset(u);
			}
		}
	}
}

void printAllToposorts() {
	vi degree(V,0);
	used.reset();
	for(int u = 0; u < V; u++) {
		for(int i = 0; i < (int)adjList[u].size(); i++) {
			degree[adjList[u][i].first]++;
		}
	}
	recurse(0,degree);
}