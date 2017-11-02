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

#define ll long long

#define ii pair<int,int>
#define iii pair<int,ii>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue

#define PI 3.14159265359
#define EPS 1e-6

int main(){
	ios_base::sync_with_stdio(false);
	int t, n, f, r; cin >> t;
	double Vol[10000];
	cout << fixed << setprecision(4);

	while (t--){
		cin >> n >> f;
		double totVol = 0.0;
		double s, e;
		for (int i = 0; i < n; i++){
			cin >> r;
			double temp = PI*r*r; 
			Vol[i] = temp;
			totVol += temp;
		}
		f++;
		s = 0.0, e = totVol/f;

		double m;
		int times = 60;
		while (times--){
			m = (e+s)/2.0;
			int tempf = f;
			for (int i = 0; i < n && tempf > 0; i++)
				tempf -= floor(Vol[i]/m);

			if (tempf <= 0)
				s = m+EPS;	
			else
				e = m-EPS;
		}
		cout << m << '\n';

		memset(Vol, 0, sizeof(Vol));
	}
	return 0;
}
