#include <vector>
#include <utility>

using namespace std;

#define UNVISITED 1
#define VISITED 2

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adjList;
vi dfs_num;
int V;

void dfs(int u){
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int)adjList[u].size(); i++) {
		ii v = adjList[u][i];
		if(dfs_num[v.first] == UNVISITED) {
			dfs(v.first);
		}
	}
}

int countCC() {
	int cc = 0;
	for(int i = 0; i < V; i++) {
		if(dfs_num[i] == UNVISITED ){
			cc++;
			dfs(i);
		}
	}
	return cc;
}