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

int g, n, m, a, b, counter, soln[101], s, best, bestSoln[101];
vector<int> empty;
vector<pair<int, vector<int>>> adjac(101);

void solve (int c = 0){

	bool done = true;
	int i;
	for (i = c; i < n && done; i++) 
		if (!adjac[i+1].first){
			done = false;
			break;
		}

	if (done){
		if (s > best){
			best = s;
			for (int i = 0; i < s; i++)
				bestSoln[i] = soln[i];
			/*
			cout << "solution:\n";
			for (int i = 0; i < n; i++) {
				if(adjac[i+1].first == 1)
					cout << i+1 << " is black\n";
				
			}
			*/
		}
		return;
	}

	for ( ; i < n; i++) {
		bool blackAround = false;
		for (auto&& v : adjac[i+1].second)
			if (adjac[v].first == 1){
				blackAround = true;
				break;
			}

		if (!adjac[i+1].first && !blackAround){
			adjac[i+1].first = 1; //black
			soln[s++] = i+1;
			for (auto&& v : adjac[i+1].second)
				adjac[v].first = 2; //whites

			solve(i+1);

			for (auto&& v : adjac[i+1].second)
				adjac[v].first = 0;
			s--;
			adjac[i+1].first = 0;
		}
	}




}



int main(){
	ios_base::sync_with_stdio(false);
	empty.reserve(100);

	cin >> g;
	while (g--){
		cin >> n >> m;
		adjac.clear();

		for (int i = 0; i < n; i++)
			adjac[i+1] = mp(0, empty);

		for (int i = 0; i < m; i++){
			cin >> a >> b;
			adjac[a].second.pb(b);
			adjac[b].second.pb(a);
		}
		s = best = 0;
		solve();
		cout << best << endl;
		for (int i = 0; i < best; i++) {
			cout << bestSoln[i];
			if (i == best-1)
				cout << '\n';
			else
				cout << ' ';
		}
	}
	return 0;
}
