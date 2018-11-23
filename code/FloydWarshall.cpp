#include <vector>

using namespace std;

typedef vector<int> vi;

#define INF 1000000000

int V;
vector<vi> adjMat;

vector<vi> dijkstras(int s){
	for(int k = 0; k < V; k++)
		for(int i = 0; i < V; i++) 
			for(int j = 0; j < V; j++) 
				adjMat[i][j] = min(adjMat[i][j],adjMat[i][k] + adjMat[k][j]);
	return adjMat;
}

