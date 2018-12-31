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

iii A[1005];
int nex[1005], memo[1005];
int n = 0, a;

int LIS(int i){
	int &ans = memo[i], &ne = nex[i];
	if (ans != 0)
		return ans;

	for (int j = i+1; j < n; j++){
		if (A[j].second.first < A[i].second.first && A[j].first != A[i].first){
			int lisNext = LIS(j);
			if (lisNext > ans){
				ans = lisNext;
				ne = j;
			}
		}
	}
	return ++ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	while (cin >> A[n].first >> A[n].second.first){
		A[n].second.second = n;
		n++;
	}
	sort(A, A+n);

	memset(memo, 0, sizeof(memo));
	a = -1;
	int start;
	for (int i = 0; i < n; i++){
		int val = LIS(i);
		if (val > a){
			a = val;
			start = i;
		}
	}
	cout << a << '\n';
	while (a--){
		int ind = A[start].second.second+1;
		cout << ind << '\n';
		start = nex[start];
	}






	return 0;
}
