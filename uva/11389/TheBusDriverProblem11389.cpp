#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
#define EPS 1e-9
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

#define endl '\n'
int n, d, r, payment;
vector<int> r1(100), r2(100);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n >> d >> r, n) {
        payment = 0;
        for (int i = 0; i < n; i++) {
            cin >> r1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> r2[i];
        }
        sort(r1.begin(), r1.begin()+n);
        sort(r2.begin(), r2.begin()+n);
        for (int i = 0; i < n; i++) {
            int overdue = r1[i]+r2[n-1-i]-d;
            if (overdue > 0) {
                payment += overdue*r;
            }
        }
        cout << payment << endl;
    }






    return 0;
}
