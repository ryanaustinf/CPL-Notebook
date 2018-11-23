#include <vector>
#include <utility>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX_N 1000

int V;
vector<vii> adjList;

int primsMST(){
	bitset<MAX_N> taken;
	priority_queue<ii> q;
	q.push(ii(0,0));
	int mst = 0;
	while(!q.empty()) {
		ii cur = q.top(); q.pop();
		int u = -cur.second, w = -cur.first;
		if(!taken.test(u)) {
			taken.set(u);
			for(int i = 0; i < (int)adjList[u].size(); i++) {
				ii v = adjList[u][i];
				if(!taken.test(v.first)) {
					q.push(ii(-v.second,-v.first));
				}
			}
			mst += w;
		}
	}
	return mst;
}

