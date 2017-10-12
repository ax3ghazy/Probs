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

//typedef later
#define ii pair<int,int>
#define iii pair<int,ii>
typedef vector<int> vi;
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue





int main(){
	ios::sync_with_stdio(false);
	int t, n, i, j, p;
	int S[5], A[5];
	int minDist = 50, tempDist, minAll, tempAll;
	int x, y;
	pair<ii, int> population[25];
  	cin >> t;
	while (t--){
		cin >> n;
		for (int k = 0; k < n; k++) {
			cin >> i >> j >> p;
			population[k] = make_pair(ii(i,j), p);
		}
		minAll = 100000000;
		for ( A[0] = 0; A[0] < 21; A[0]++) {
			for ( A[1] = A[0]+1; A[1] < 22; A[1]++) {
				for ( A[2] = A[1]+1; A[2] < 23; A[2]++) {
					for ( A[3] = A[2]+1; A[3] < 24; A[3]++) {
						for ( A[4] = A[3]+1; A[4] < 25; A[4]++) {
							tempAll = 0;
							for (int k = 0; k < n; k++) {
								minDist = 50;
								i = population[k].first.first, j = population[k].first.second;
								for (int m = 0; m < 5; m++) {
									x = A[m]/5, y = A[m]%5;										
									tempDist = abs(i-x)+abs(j-y);
									if (tempDist < minDist)
										minDist = tempDist;
								}
								tempAll += minDist*population[k].second;
							}
							if (tempAll < minAll){
								minAll = tempAll;
								memcpy(S, A, 20);
							}
						}
					}	
				}
			}
		}
		for (int k = 0; k < 4; k++)
			cout << S[k] << ' ';
		cout << S[4] << '\n'; //no checks at all


	}

	



	return 0;
}

