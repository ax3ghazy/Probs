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

string X, Y;
int m, n;
int memo[1000][1000];

int lcs(int i, int j){
	if (i < 0 || j < 0)
		return 0;
	int &ans = memo[i][j];
	if (ans != -1)
		return ans;
	char xlast = X[i], ylast = Y[j];
	if (xlast == ylast)
		return ans = 1 + lcs(i-1, j-1);
	return ans = max(lcs(i-1,j), lcs(i,j-1));
}


int main(){
	ios_base::sync_with_stdio(false);
	while (getline(cin, X) && getline(cin, Y)){
		n = X.length();
		m = Y.length();
		memset(memo, -1, sizeof(memo));
		cout << lcs(n-1,m-1) << '\n';
	}
	return 0;
}
