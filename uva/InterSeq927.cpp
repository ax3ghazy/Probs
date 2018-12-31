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
#define ssf(a) scanf("%s", a)
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

long long eval(int C[], int d, long long n){
	long long out = C[d];
	while (d)
		out = out * n + C[--d];
	return out;
}


int main(){
	int t, i, C[20], c, d, k;
	long long n, n2;
	sdf(t);
	while(t--){
		sdf(i);
		for (int j = 0; j < i+1; j++) {
			sdf(c);
			C[j] = c;	
		}

		sdf(d); sdf(k);
		k = 2*(k-1)/d;
		n2 = 1, n = 1;
		while (k < n2-n || k > n2+n-1)
			n2 += 2*(n++) +1;	

		printf("%lld\n", eval(C, i, n));
	}
	



	return 0;
}



