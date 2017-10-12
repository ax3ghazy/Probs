#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int m, i, j, minSteps, worstCase, tempSteps, e1, e3;
	string color;
	vector< pair<int,int> > ones(10000), threes(10000);
	while (cin >> m){
		e1 = e3 = worstCase = 0;
		for (i = 0; i < m; i++){
			cin >> color;
			for (j = 0; j < m; j++){
				if (color[j] == '1')
					ones[e1++] = make_pair(i,j);
				else if (color[j] == '3')
					threes[e3++] = make_pair(i,j);
			}
		}
		for (i = 0; i < e1; i++){
			minSteps = 10000000;
			for (j = 0; j < e3; j++){
				tempSteps = abs(ones[i].first-threes[j].first)+abs(ones[i].second-threes[j].second);
				if (tempSteps < minSteps)
					minSteps = tempSteps;
			}
			if (minSteps > worstCase)
				worstCase = minSteps;
		}
		cout << worstCase << '\n';
		
		
	}
	return 0;
}