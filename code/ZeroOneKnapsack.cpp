#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

/**
 * item.first - weight of item
 * item.second - value of item
 */
int zeroOneKnapsack(const vii &items, int maxWeight) {
	vector<vi> memo(items.size(),vi(maxWeight + 1,0));
	for(int i = 0; i < (int)items.size(); i++ ) {
		for(int j = 0; j <= maxWeight; j++) {
			if(i == 0){
				memo[i][j] = j >= items[0].first ? items[0].second : 0;
			} else {
				memo[i][j] = memo[i - 1][j];
				if(j >= items[i].first) {
					memo[i][j] = max(memo[i][j],
						memo[i - 1][j - items[i].first] + items[i].second);
				}
			}
		}
	}
	return memo[(int)items.size() - 1][maxWeight];
}