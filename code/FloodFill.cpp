#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define MAX_R 1000
#define MAX_C 1000

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int grid[MAX_R][MAX_C];
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

int iterativeFloodFill(int r, int c, int v1, int v2){
	if(r >= 0 && r < MAX_R && c >= 0 && c < MAX_C && grid[r][c] == v1) {
		queue<int> q;
		q.push(r * MAX_C + c);
		int area = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			int inR = u / MAX_C;
			int inC = u % MAX_C;
			grid[inR][inC] = v2;
			area++;
			for(int i = 0; i < 4; i++) {
				int nr = inR + dr[i];
				int nc = inC + dc[i];
				if(nr >= 0 && nr < MAX_R && nc >= 0 && nc < MAX_C && 
					grid[nr][nc] == v1) {
					q.push(nr * MAX_C + nc);
				}
			}
		}
		return area;
	}
	return 0;
}

int recursiveFloodFill(int r, int c, int v1, int v2) {
	if(r >= 0 && r < MAX_R && c >= 0 && c < MAX_C && grid[r][c] == v1) {
		grid[r][c] = v2;
		int area = 1;
		for(int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			area += recursiveFloodFill(nr,nc,v1,v2);
		}
		return area;
	} else {
		return 0;
	}
}