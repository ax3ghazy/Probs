#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <ctime>
#include <chrono> //C++11
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <functional>
#include <cstring>
using namespace std;

#define inf 0x7fffffff //32-bit int
#define ninf 0x80000000
#define mp(A,B) make_pair(A,B)
#define sdf(n) scanf("%d",&n)
#define ssf(a) scanf(" %s ", a)
#define pdf(n) printf("%d",n)
#define pcf(c) printf("%c",c)
#define pdfn(n) printf("%d\n",n)
#define pb push_back
#define pendl() printf("\n")

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

//typedef later
#define ii pair<int,int>
#define iii pair<int,ii>
typedef vector<int> vi;
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue
char gridA[6][5], gridB[6][5];
char gridS[6][5], gridLim[5];
int s, t, k;
char soln[5], c;
set<string> solns;

void solve(int c = 0){

	if(c==5){
		if (!solns.count(string(soln))){
			s++;
			solns.insert(string(soln));
		}
		return;
	}

	int lim = gridLim[c];
	for (int i = 0; i < lim; i++) {
		soln[c] = gridS[i][c];
		solve(c+1);
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> k;
		solns.clear();
		s = 0;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 5; j++)
				cin >> gridA[i][j];

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 5; j++)
				cin >> gridB[i][j];

		fill(gridLim, gridLim+5, 0);
		for(int c = 0; c < 5; c++)
			for (int i = 0; i < 6; i++) {
				char A = gridA[i][c];
				for (int j = 0; j < 6; j++) {
					if (A == gridB[j][c]){
						int k;
						for (k = 0; k < gridLim[c] ; k++) {
							if (A == gridS[k][c])
								break;
						} 
						if (k == gridLim[c])
							gridS[gridLim[c]++][c] = A;
					}
				}
			}

		solve();
		if (k > s)
			cout << "NO";	
		else{
			int i = 1;
			for (auto it = solns.begin(); it != solns.end(); it++, i++ )
				if (i == k){
					cout << *it;
					break;
				}
		}
		cout << '\n';
	}
	return 0;
}
