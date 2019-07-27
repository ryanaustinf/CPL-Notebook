#include <vector>

using namespace std;

typedef vector<int> vi;

/**
 * Segment tree for Range Maximum Queries
 */
class SegmentTree {
	public:
	vi st, A;
	int n;
	SegmentTree(const vi &_A) {
		A = _A;
		n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int l, int r) {
		if(l == r) {
			st[p] = l;
		} else {
			int m = l + (r - l) / 2;
			build(left(p),l,m);
			build(right(p),m + 1,r);
			int s1 = st[left(p)];
			int s2 = st[right(p)];
			st[p] = A[s1] <= A[s2] ? s1 : s2;
		}
	}
	int rmq(int i, int j) {
		return rmq(1,0,n-1,i,j);
	}
	int rmq(int p, int l, int r, int i, int j) {
		if(l > j || r < i) { return -1; }
		else if(l >= i && r <= j) { return st[p]; } 
		else {
			int m = l + (r - l) / 2;
			int s1 = rmq(left(p),l,m,i,j);
			int s2 = rmq(right(p),m + 1,r,i,j);
			if(s1 == -1) {return s2;}
			else if(s2 == -1) {return s1;}
			else {return A[s1] <= A[s2] ? s1 : s2; }
		}
	}
	void pointUpdate(int i, int val) {
		pointUpdate(1,0,n-1,i,val);
	}
	void pointUpdate(int p, int l, int r,int i, int val) {
		if(l == r) {
			A[i] = val;
		} else {
			int m = l + (r - l) / 2;
			if(i >= l && i <= m) {
				pointUpdate(left(p),l,m,i,val);
			} else {
				pointUpdate(right(p),m + 1,r,i,val);
			}
			int s1 = st[left(p)];
			int s2 = st[right(p)];
			st[p] = A[s1] <= A[s2] ? s1 : s2;
		}
	}
};