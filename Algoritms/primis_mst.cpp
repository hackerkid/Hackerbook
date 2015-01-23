#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int a[100][100];
	int dis[100];
	int source[100];
	int edges;
	int inTree[100];
	int cost;
	int count;

	count = 0;
	cost = 0;
	cin >> edges;

	for (int i = 0; i < edges; i++) {
		for (int j = 0; j < edges; j++) {
			cin >> a[i][j];
		}

	}


	for (int i = 0; i < edges; i++) {
		dis[i] = INT_MAX;
	}

	for (int i = 0; i < edges; i++) {
		source[i] = -1;
	}

	for (int i = 0; i < edges; i++) {
		inTree[i] = 0;
	}


/*
	for (int i = 1; i < edges; i++) {
		if(a[1][i] != 0 ) {
			dis[i] = a[1][i];
			source[i] = 1;
		}

	}
*/

	count = 0;
	int min;
	int temp = 0;
	int val;
	dis[0] = 0;

	while(count < edges) {
		min = INT_MAX;
		for (int i = 0; i < edges; i++) {
			if(inTree[i] == 0 and dis[i] < min ) {
				min = dis[i];
				val = i;
				temp++;
			}

		}
		
		if(min == INT_MAX) {
			
			cout << "MST NOT POSSIBLE|N"<<endl;
			return 0;
		}


		count++;
		inTree[val] = 1;
		dis[val] = min;
		cost += min;

		
		for (int i = 0; i < edges; i++) {
			if(a[val][i] != 0 and inTree[i] != 1) {
				if(a[val][i] < dis[i]) {
					source[i] = val;
					dis[i] = a[val][i];
				}

			}

		}



	}

	cout << cost << endl;





}

