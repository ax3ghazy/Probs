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


int spare[32], row[32], used, n, m, r, l;
bool solved;
void solve(int c = 2){
	//if done
	if (c == (n<<1)+2){
		if (row[c] == row[c-1]){
			cout << "YES\n";
			solved = true;
		}
		return;
	}

	for (int i = 0; i < (m<<1) && !solved; i += 2) {
		bool eff = (spare[i+1] == row[c-1]);
		if (!isOn(used,i) && (spare[i] == row[c-1] || eff)){
			row[c+1] = spare[i+!eff];

			setBit(used,i);
			
			solve(c+2);
			
			clearBit(used,i);
		}
	}	

}


int main(){
	ios_base::sync_with_stdio(false);

	while(cin >> n, n){
		cin >> m;
		cin >> row[0] >> row[1] >> row[(n<<1)+2] >> row[(n<<1)+3];
		for (int i = 0; i < (m<<1); i+=2)
			cin >> spare[i] >> spare[i+1];	

		used = 0;
		solved = false;
		solve();
		if(!solved)
			cout << "NO\n";
	}
	return 0;
}
