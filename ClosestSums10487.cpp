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
#include <climits>
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

int main() { //trying hard to get '0 time'
	ios::sync_with_stdio(false);
	long long n, a, i, j, m, closestSum, closestDiff, tempSum, tempDiff, count = 1, A[1000]; 
	while (cin >> n, n){
		cout << "Case " << count++ << ":\n";
		for (i = 0; i < n; i++){
			cin >> a;
			A[i] = a;
		}
		cin >> m;
		while (m--){
			cin >> a;
			closestDiff = LONG_MAX;
			for (i = 0; i < n; i++)
				for (j = i+1; j < n; j++){
					tempSum = A[i]+A[j];
					tempDiff = tempSum > a? tempSum-a : a-tempSum;
					if (tempDiff < closestDiff){
						closestDiff = tempDiff;
						closestSum = tempSum;
					}
				}
			cout << "Closest sum to " << a << " is " << closestSum << ".\n";
		}
	}
	
	return 0;
	
}

















