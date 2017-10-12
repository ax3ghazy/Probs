#include <iostream>
#include <cstdio>
#include <iomanip>
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

int main() { 
	ios::sync_with_stdio(false);
	int fN, i, j, di, rN, f, r, dN, F[15];
	double d, D[105], maxSpread, tempSpread;
	while (cin >> fN, fN){
		cin >> rN;
		for (i = 0; i < fN; i++){
			cin >> f;
			F[i] = f;
		}
		di = 0;
		for (i = 0; i < rN; i++){
			cin >> r;
			for (j = 0; j < fN; j++)
				D[di++] = double(r)/F[j];
		}
		sort(D, D+di);
		maxSpread = 0.;
		for (i = 1; i < di; i++){
			tempSpread = D[i]/D[i-1];
			if (tempSpread > maxSpread)
				maxSpread = tempSpread;
		}
		cout << fixed << setprecision(2) << maxSpread << '\n';
	}
	return 0;
}

















