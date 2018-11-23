#include <vector>
#include <utility>
#include <bitset>
#include <stack>

using namespace std;

#define MAX_N 1000

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adjList;
vi dfs_num, dfs_low;
bitset<MAX_N> visited;

int dfsCtr = 0, V, scc;

void tarjan(int u,stack<int> &s){
	// printf("Tarjan(%d)\n",u);
	dfs_num[u] = dfs_low[u] = dfsCtr++;
	s.push(u);
	visited.set(u);
	for(int i = 0; i < (int)adjList[u].size(); i++) {
		ii v = adjList[u][i];
		if(dfs_num[v.first] == -1) {
			tarjan(v.first,s);
		}
		if(visited.test(u)) {
			dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
		}
	}
	if(dfs_low[u] == dfs_num[u]) {
		printf("SCC #%d:",++scc);
		while(s.top() != u) {
			int temp = s.top();	s.pop();
			printf(" %d",temp);
		}
		printf(" %d\n",s.top());
		s.pop();
	}
}

int printAndCountSCCs(){
	scc = 0;
	visited.reset();
	stack<int> s;
	dfs_num.assign(V,-1);
	dfs_low.assign(V,-1);
	for(int i = 0; i < V; i++) {
		// printf("dfs_num[%d] = %d\n",i,dfs_num[i]);
		if(dfs_num[i] == -1) {
			tarjan(i,s);
		}
	}
	return scc;
}