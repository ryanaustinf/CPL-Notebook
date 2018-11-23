#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;

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

int V,E;
vector<iii> edgeList;

/**
 * Store edges in edge list where first contains the edge weight and second 
 * contains a pair with the endpoints.
 */
int kruskalsMST() {
	int mst = 0;

	sort(edgeList.begin(),edgeList.end());
	UnionFind uf(V);
	for(int i = 0; i < E; i++) {
		iii edge = edgeList[i];
		if(!uf.isSameSet(edge.second.first,edge.second.second)) {
			uf.unionSet(edge.second.first,edge.second.second);
			mst += edge.first;
		}
	}
}