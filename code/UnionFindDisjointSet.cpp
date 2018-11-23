#include <vector>

using namespace std;

typedef vector<int> vi;

class UnionFind {
	public:
	vi p, rank;
	UnionFind(int n) {
		p.assign(n,0);
		rank.assign(n,0);
		for(int i = 0; i < n; i++) { p[i] = i; }
	}

	void unionSet(int i, int j) {
		if(!isSameSet(i,j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if(rank[x] == rank[y]) { rank[y]++; }
			}
		}
	}

	int findSet(int i) {
		if(p[i] != i) {
			p[i] = findSet(p[i]);
		}
		return p[i];
	}

	bool isSameSet(int i, int j) { return findSet(i) == findSet(j);}
};