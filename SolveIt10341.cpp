#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <ctime>
#include <chrono> //C++10
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
#define eps 0.0001f
#define eps2 0.0000001f

int p,q,r,se,t,u, test;
double s, e, c;



inline float f(float x) {
    return p*exp(-x)+q*sin(x)+r*cos(x)+se*tan(x)+t*x*x+u;
}

int main(){
	ios_base::sync_with_stdio(false);
	while (cin >> p) {
		cin >> q >> r >> se >> t >> u;
		if (f(1.0) > 0.0 || p+r+u < 0.0){
			cout << "No solution\n";
			continue;
		}
		s = 0.0, e = 1.0;
		test = 30;
		double fe = f(e), fm;
		while (test--){
			c = (s+e)/2.0;
			fm = f(c);
			if (fm > 0.0)
				s = c;
			else
				e = c;

		}
		cout << fixed << setprecision(4) << c << '\n';
	}





	return 0;
}
