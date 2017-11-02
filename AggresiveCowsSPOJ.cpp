#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
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


int main(){
	ios_base::sync_with_stdio(false);
	int t, N, C; cin >> t;
	int loc[100000];
	while (t--){
		cin >> N >> C;
		int least = inf, most = ninf;
		for (int i = 0; i < N; i++){
			int temp; cin >> temp;
			loc[i] = temp;
			least = min(least, temp);
			most = max(most, temp);
		}
		sort(loc, loc+N);
		int s = 1, e = most-least+1;
		int m;
		int best = 1;
		while (e >= s){
			m = (s+e)/2;
			int distance = 0, tempC = C-1;
			for (int i = 1; i < N && tempC; i++){
				distance += loc[i]-loc[i-1];
				if (distance >= m){
					tempC--;
					distance = 0;
				}
			}
			if (tempC == 0){
				s = m+1;
				best = max(best, m);
			}
			else
				e = m-1;
		}
		cout << best << '\n';

	}






	return 0;
}
