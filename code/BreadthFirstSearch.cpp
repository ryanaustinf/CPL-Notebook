#include <vector>
#include <utility>
#include <queue>
#include <bitset>

using namespace std;

#define MAX_N 1000

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adjList;

void bfs(int s){
	bitset<MAX_N> visited;
	queue<int> q;
	q.push(s);
	visited.set(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < (int)adjList[u].size(); i++) {
			ii v = adjList[u][i];
			if(!visited.test(v.first)) {
				visited.set(v.first);
				q.push(v.first);
			} 
		}
	}
}

