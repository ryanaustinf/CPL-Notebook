#include <vector>
#include <utility>
#include <bitset>

using namespace std;

#define MAX_N 1000

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adjList;
vi dfs_num, dfs_low, dfs_parent;
bitset<MAX_N> isArticulationPoint;

int dfsCtr = 0, V, children, dfsRoot;

void dfs(int u,vii &bridges){
	dfs_num[u] = dfs_low[u] = dfsCtr++;
	for(int i = 0; i < (int)adjList[u].size(); i++) {
		ii v = adjList[u][i];
		if(dfs_num[v.first] == -1) {
			dfs_parent[v.first] = u;
			dfs(v.first,bridges);
			if(u == dfsRoot) {
				children++;
			}

			dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
			if(dfs_num[u] <= dfs_low[v.first]) {
				isArticulationPoint.set(u);
			}
			if(dfs_num[u] < dfs_low[v.first]) {
				bridges.push_back(ii(u,v.first));
			}
		} else if(v.first != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
		}
	}
}

pair<vi,vii> findArticulationPointsAndBridges(){
	vii bridges;
	isArticulationPoint.reset();
	dfs_num.assign(V,-1);
	dfs_low.assign(V,-1);
	dfs_parent.assign(V,-1);
	for(int i = 0; i < V; i++) {
		if(dfs_num[i] == -1) {
			children = 0;
			dfsRoot = i;
			dfs(i,bridges);
			if(children > 1) {
				isArticulationPoint.set(i);
			} else {
				isArticulationPoint.reset(i);
			}
		}
	}
	vi artPoints;
	for(int i = 0; i < V; i++) {
		if(isArticulationPoint.test(i)) {
			artPoints.push_back(i);
		}
	}
	return pair<vi,vii>(artPoints,bridges);
}

