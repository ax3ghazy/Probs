#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <functional>
#include <cstring>
using namespace std;

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
	int k, x, y, nom, denom, m;
	vector<ii> soln(10010);
	while (sdf(k) == 1){
		m = 0;
		y = k;
		do{
			y++;
			nom = k*y;
			denom = y-k;
			if (!(nom%denom)){
				x = nom/denom;
				soln[m++] = ii(x, y);
			}
		} while (y <= x);
		pdfn(m);
		for (int i = 0; i < m; i++) 
				printf("1/%d = 1/%d + 1/%d\n", k, soln[i].first, soln[i].second);
		
	}
	


	return 0;
}
