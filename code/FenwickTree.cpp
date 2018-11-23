#include <vector>

using namespace std;

typedef vector<int> vi;

class FenwickTree {
	public:
	vi ft;
	int n;
	FenwickTree(int _n) {
		n = _n;
		ft.assign(n + 1,0);
	}

	void update(int index, int increment) {
		while(index <= n) {
			ft[index] += increment;
			index += (index & (-index));
		}
	}

	int rmq(int end) {
		int res = 0;
		while(end) {
			res += ft[end];
			end -= (end & (-end));
		}
		return res;
	}

	int rmq(int i, int j) {
		if(i > j) { return 0; }
		else if(i <= 0) { return rmq(j); }
		else {return rmq(j) - rmq(i - 1)}
	}
};