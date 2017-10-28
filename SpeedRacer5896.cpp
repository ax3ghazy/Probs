#include <bits/stdc++.h>
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

#define EPS 1e-7
double v, a, b, c, d, m, t;

inline double f(){
	double V = v;
	//double res = a*v*v*v*v + b*v*v*v + c*v*v + d*v;
	double res = 0.0;
	res += V*d;
	V = V*V;
	res += V*c;
	res += V*v*b;
	res += V*V*a;
	//useless optimization
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(2);
	while (cin >> a >> b >> c >> d >> m >> t){
		double bestV = -1.0;
		double s = 0.0, e = 1000.0;
		while (e-s > EPS){
			//cout << v << '\n';
			v = (s+e)/2.0;
			double h = m/v;
			if (f()*h <= t)
				s = v + EPS;
			else
				e = v - EPS;
		}
		cout << floor(v*100.0)/100.0 << '\n';






	}



	return 0;
}
