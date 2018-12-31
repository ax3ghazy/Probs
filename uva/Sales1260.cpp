#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <bitset>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cctype>
#include <cmath>
#include <functional>
#include <cstring>
using namespace std;

#define mp(A,B) make_pair(A,B)
#define mxstr 100000000
#define sdf(n) scanf("%d",&n)
#define sdfn(n) scanf("%d\n",&n)
#define sds(a) scanf("%s", a)
#define pdf(n) printf("%d",n)
#define pdfn(n) printf("%d\n",n)
#define pb push_back
#define pendl() printf("\n")

//typedef later
#define ii pair<int,int>
#define iii pair<int,ii>
#define pque priority_queue
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main() {
	ios::sync_with_stdio(false);
	int t, n, i, temp, s, sum, A[1000];
//	B[0] = 0;
	cin >> t;
	while (t--){
		cin >> n;
		sum = 0;
		for (i = 0; i < n; i++){
			cin >> s;
			A[i] = s;
			temp = 0;
			for (int j = i-1; j > -1; j--)
				if (A[j] <= s)
					temp++;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}