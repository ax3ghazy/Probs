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


int soln[12], numSet[12], current, desired, n, solns[5000][12], s, pattern;

void solve (int m = 0, int x = 0){
	//if done
	if (current == desired){
		int j;
		bool repeated = false;
		for (int i = 0; i < s && !repeated; i++){
			for (j = 0; j < m; j++)
				if (solns[i][j] != soln[j])
					break;
			if (j==m)
				repeated = true;
		}


		if (!repeated){
			cout << soln[0];
			solns[s][0] = soln[0];
			for (int i = 1; i < m; i++){
				cout << '+' <<  soln[i];
				solns[s][i] = soln[i];
			}
			s++;
			cout << '\n';
		}
		return;
	}
	if (m == n)
		return;

	for (int i = x; i < n; i++) {
		int temp = numSet[i];
		if (current + temp <= desired){
			soln[m] = temp;

			current += temp;

			solve(m+1, i+1);

			current -= temp;
		}
	}

}




int main(){
	ios_base::sync_with_stdio(false);
	while (cin >> desired >> n, n){
		for (int i = 0; i < n; i++)
			cin >> numSet[i];
		cout << "Sums of " << desired << ":\n";
		current = s = 0;
		solve();
		if (!s)
			cout << "NONE\n";
	}


	return 0;
}
