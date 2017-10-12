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


int main(){
	int t, e, v;
	int connecs, acorns;
	char a, b, c;
	sdfn(t);
	while (t--){
		bitset<26> pool;
		e = v = 0;
		acorns = 0;
		while(scanf("%c", &c), c == '('){
			scanf("%c, %c)\n", &a, &b);
			pool.set(a-'A');
			pool.set(b-'A');
			++e;
		}
		cin.ignore(1000,'\n');
		while(scanf("%c", &c) == 1 && c != '\n'){
			if (isalpha(c)){
				if (!pool[c-'A'])
					++acorns;
				++v;
			}
		}
		connecs = v - e;
		printf("There are %d tree(s) and %d acorn(s).\n", connecs-acorns, acorns);
		
		
	}
	
	
	return 0;
}