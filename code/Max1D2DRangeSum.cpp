#include <vector>

using namespace std;

typedef vector<int> vi;

int max1DRangeSum(const vi &arr) {
	int ans = 0;
	int cur = 0;
	for(int i = 0; i < (int)arr.size(); i++) {
		cur += arr[i];
		if(cur < 0) cur = 0; 
		ans = max(ans,cur);
	}
	return ans;
}

int max2DRangeSum(const vector<vi> &arr) {
	vi rowSums(arr.size(),0);
	for(int i = 0; i < (int)arr.size(); i++) {
		for(int j = 0; j < (int)arr[i].size(); j++) {
			rowSums[i] += arr[i][j];
		}
	}

	int ans = 0;
	for(int leftCol = 0; leftCol < (int)arr[0].size(); leftCol++) {
		for(int rightCol = leftCol; rightCol < (int)arr[0].size(); rightCol++) {
			vi arr2(arr.size(),0);
			for(int i = 0; i < (int)arr.size(); i++) {
				arr2[i] = leftCol == 0 ? rowSums[rightCol] : 
									(rowSums[rightCol] - rowSums[leftCol - 1]);
			}
			int temp = max1DRangeSum(arr2);
			ans = max(ans,temp);
		}
	}
	return ans;
}