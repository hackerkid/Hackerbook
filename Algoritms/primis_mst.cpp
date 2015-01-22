#include <iostream>
#include <limits.h>
#define V 5
using namespace std;

int main()
{
	int a[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

	int dis[100];
	int source[100];
	int edges;
	int inTree[100];
	int cost;
	bool count;

	count = 0;
	cost = 0;
	edges = 5;
//	cin >> edges;
/*
	for (int i = 0; i < edges; i++) {
		for (int j = 0; j < edges; j++) {
			cin >> a[i][j];
		}

	}

*/
	for (int i = 0; i < edges; i++) {
		dis[i] = INT_MAX;
	}

	for (int i = 0; i < edges; i++) {
		source[i] = -1;
	}

	for (int i = 0; i < edges; i++) {
		inTree[i] = 0;
	}


	dis[0] = 0;
	inTree[0] = 1;
	count = 1;

	for (int i = 1; i < edges; i++) {
		if(a[1][i] != 0 ) {
			dis[i] = a[1][i];
			source[i] = 1;
		}

	}

	int min;
	while(count != edges) {
		min = INT_MAX;
		int val;
		for (int i = 1; i < edges; i++) {
			if(inTree[i] == 0 and dis[i] < min) {
				min = dis[i];
				val = i;
			}

		}
		
		if(min == INT_MAX) {
			cout << "MST NOT POSSIBLE|N"<<endl;
			return 0;
		}

		
		count++;
		inTree[val] = 1;
		dis[val] = min;
		cost += dis[val];

		
		for (int i = 0; i < edges; i++) {
			if(a[val][i] != 0) {
				if(a[val][i] < dis[i]) {
					source[i] = val;
					dis[i] = a[val][i];
				}

			}

		}



	}

	cout << count;




}

