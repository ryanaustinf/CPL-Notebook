#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int lisSlow(const vi &arr) {
	vi memo(arr.size(),1);
	int ans = 1;
	for(int i = 1; i < (int)arr.size(); i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j]) {
				memo[i] = max(memo[i],memo[j] + 1);
			}
		}
		ans = max(ans,memo[i]);
	}
	return ans;
}

int lisNLogN(const vi &arr) {
	vi memo;

	for(int i = 0; i < (int)arr.size(); i++) {
		vi::iterator itr = lower_bound(memo.begin(),memo.end(),arr[i]);
		if(itr == memo.end()) {
			memo.push_back(arr[i]);
		} else {
			*itr = arr[i];
		}
	}
	return (int)memo.size();
}