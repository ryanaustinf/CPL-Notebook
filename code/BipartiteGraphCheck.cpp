#include <vector>
#include <utility>
#include <queue>
#include <bitset>

using namespace std;

#define MAX_N 1000
#define NO_COLOR -1

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int V;
vector<vii> adjList;

bool isBipartite(int s){
	queue<int> q;
	q.push(s);
	vi color(V,NO_COLOR);
	color[s] = 0;
	bool isBipartite = true;
	while(!q.empty() && isBipartite) {
		int u = q.front(); q.pop();
		for(int i = 0; i < (int)adjList[u].size(); i++) {
			ii v = adjList[u][i];
			if(color[v.first] == NO_COLOR) {
				color[v.first] = 1 - color[u];
				q.push(v.first);
			} else if(color[v.first] == color[u]) {
				isBipartite = false;
			}
		}
	}
	return isBipartite;
}

