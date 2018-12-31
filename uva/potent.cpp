#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPower2 (int n){
	if (!n) return false;
	return !(n&(n-1));
}


int main (){
	int n;
	while (!(cin >> n).eof()){
		vector<int> pots(1 << n, 0);
		for (int i = 0; i < (1 << n); i++){
			int w; cin >> w;
			//pots[i] += w;
			for (int j = 0; j < (1 << n); j++)
				if ( isPower2(i^j) )
					pots[j] += w;
		}
		int max = -1;
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < (1 << n); j++)
				if ( isPower2(i^j) && pots[i]+pots[j] > max &&  i!=j) max = pots[i]+pots[j]; 
		cout << max << endl;
	}


	return 0;
}

