#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
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
#define pque priority_queue

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

//#define endl '\n'
#define EPS 1e-5

int T;
int cf[15];

inline double poly(double x) {
    double sum = cf[0];
    for (int i = 0; i <= T-1; i++) {
        sum *= x;
        sum += cf[i+1];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> T, T) {
        for (int i = 0; i <= T; i++) {
            cin >> cf[i];
        }
        double s = 0.02, e = 1e20, m;
        //if (poly(e) < 0) {
          //  cerr << "There's a soln" << endl;
        //}
        while (e-s >= EPS) {
            //cerr << "@ " << s  << " <-> " << e << endl;
            m = (s+e)/2.0;
            double val = poly(m);
            if (val > 0) {
                s = m;
            } else if (val < 0) {
                e = m;
            } else {
                break;
            }
        }
        s = round(100.0*s)/100.0;
        s -= 1.0;
        //cerr << s << endl;
        cout << fixed << setprecision(2) << s << endl;
    }






    return 0;
}
