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
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
typedef vector<int> vi;
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue


ll solve (ll n, ll r, ll s, ll e){
	if (s > e)
		return 0LL;
	s %= n; e %= n;
	if (n == 1LL)
		return 1LL;
	ll mid = (unsigned long long)n>>1ULL;
	if (r < mid)
		return solve(mid, r%mid, s , min(e, mid-1LL)) + solve(mid, r%mid, max(s,mid), e);
	else
		return solve(mid, r%mid, s , min(e, mid-1LL)) - solve(mid, r%mid, max(s,mid), e);
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, r, s, e;
	while (cin >> n >> r >> s >> e, n != -1LL)
		cout << solve(1LL << n, r, s ,e) << '\n';
	return 0;
}
