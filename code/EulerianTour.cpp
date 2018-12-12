list<int> cyc; // we need list for fast insertion in the middle
void EulerTour(list<int>::iterator i, int u) {
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (v.second) { // if this edge can still be used/not removed
			v.second = 0; // make the weight of this edge to be 0 (‘removed’)
			for (int k = 0; k < (int)AdjList[v.first].size(); k++) {
				ii uu = AdjList[v.first][k]; // remove bi-directional edge
				if (uu.first == u && uu.second) {
					uu.second = 0;
					break;
				} 
			}
			EulerTour(cyc.insert(i, u), v.first);
		} 
	} 
}
// inside int main()
cyc.clear();
EulerTour(cyc.begin(), A); // cyc contains an Euler tour starting at A
for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++)
printf("%d\n", *it); // the Euler tour