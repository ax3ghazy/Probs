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
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue


int main (){
	int m, n, r, i, j, t;
	while(scanf("%d %d", &m, &n) == 2){
		vector<vii> adjList(n+1);
		for (i = 0; i < m; i++){
			sdf(r);
			vector<int> ind(r);
			for	(j = 0; j < r; j++){
				sdf(t);
				ind[j] = t;
			}
			for	(j = 0; j < r; j++){
				sdf(t);
				adjList[ind[j]].pb(ii(i+1,t));
			}
		}
		printf("%d %d\n", n, m);
		for (i = 0; i < n; i++){
			int sz = adjList[i+1].size();
			sort(adjList[i+1].begin(), adjList[i+1].end());
			printf("%d", sz);
			for (int j = 0; j < sz; j++)
				printf(" %d", adjList[i+1][j].first);
			pendl();
			for (int j = 0; j < sz; j++){
				if (j) printf(" ");
				printf("%d", adjList[i+1][j].second);
			}
			pendl();
		}
	}
	
	
	
	
	return 0;
}