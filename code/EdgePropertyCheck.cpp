#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

#define UNVISITED 1
#define VISITED 2
#define EXPLORED 3

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adjList;
vi dfs_parent;
vi dfs_num;

void dfs(int u){
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int)adjList[u].size(); i++) {
		ii v = adjList[u][i];
		if(dfs_num[v.first] == UNVISITED) {
			printf("Edge (%d,%d): Tree Edge\n",u,v.first);
			dfs_parent[v.first] = u;
			dfs(v.first);
		} else if(dfs_num[v.first] == VISITED) {
			if(v.first == dfs_parent[u]) {
				printf("Edge (%d,%d): Two-Way Edge\n",u,v.first);
			} else {
				printf("Edge (%d,%d): Back Edge\n",u,v.first);
			}
		} else {
			printf("Edge (%d,%d): Forward/Cross Edge\n",u,v.first);
		}
	}
	dfs_num[u] = EXPLORED;
}

