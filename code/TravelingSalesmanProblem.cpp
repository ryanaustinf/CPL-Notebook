#include <vector>

using namespace std;

typedef vector<int> vi;

int n; // number of nodes
int start; //start node

vector<vi> memo(n,vi(1 << n, -1));
vector<vi> dists; // 2D distance matrix

int tsp(int pos, int mask) {
	if(mask == (1 << n) - 1) {
		return dists[pos][start];
	} else if(memo[pos][mask] != -1) {
		return memo[pos][mask];
	} else {
		int &res = memo[pos][mask];
		for(int i = 0; i < n; i++) {
			if((mask & (1 << i)) == 0) {
				res = min(res,dists[pos][i] + tsp(i,mask | (1 << i)));
			}
		}
		return res;
	}
}