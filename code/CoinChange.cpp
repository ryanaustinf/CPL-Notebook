#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

/**
 * returns minimum coins
 */
int coinChangeV1(const vi &denoms, int total) {
	vi memo(total + 1,1 << 29);
	memo[0] = 0;
	for(int i = 1; i <= total; i++) {
		for(int j = 0; j < (int)denoms.size(); j++) {
			if(i - denoms[j] >= 0) {
				memo[i] = min(memo[i],memo[i - denoms[j]] + 1);
			}	
		}
	}
	return memo[total];
}

/**
 * returns number of ways to give change
 */
int coinChangeV2(const vi &denoms, int total) {
	vector<vi> memo(denoms.size(),vi(total + 1,0));
	for(int i = 0; i < (int)denoms.size(); i++) {
		for(int j = 0; j <= total; j++) {
			if(i == 0) {
				memo[i][j] = j % denoms[0] ? 1 : 0;
			} else {
				memo[i][j] = 0;
				int count = 0;
				while(j - count * denoms[i] >= 0) {
					memo[i][j] += memo[i - 1][j - count * denoms[i]];
					count++;
				}
			}
		}
	}
	return memo[(int)denoms.size() - 1][total];
}