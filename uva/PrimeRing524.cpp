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

const int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
int soln[16];
int existing;
int n, p, temp, t;



void solve(int i = 1){
	if (!existing){
		temp = soln[n-1] + soln[0];
		for (p = 0; p < 11 && primes[p] != temp; p++);
		if (p != 11){
			for (int j = 0; j < n; j++){
				cout << soln[j];
				if (j == n-1)
					cout << '\n';
				else
					cout << ' ';
			}
		}
	}
	for (int j = 2; i < n && j <= n; j++){
		if (isOn(existing, j-1)){
			temp = j + soln[i-1];
			for (p = 0; p < 11 && primes[p] != temp; p++);
			if(p != 11){
				clearBit(existing, j-1);
				soln[i] = j;
				solve(i+1);
				setBit(existing, j-1);
			}
		}
	}
}





int main(){
	soln[0] = 1;
	t = 0;
	while(cin >> n){
		if(t)
			cout << '\n';
		cout << "Case " << ++t <<":\n";
		setAll(existing, n-1);
		existing <<= 1;
		solve();
	}
	
	return 0;
}

