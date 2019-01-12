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

vector<ll> ind(31269);



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k = 2, d = 1, hi = 10;
    ll prevleng = 1;
    ind[1] = 1;
    while (k <= 31269) {
        ind[k] = ind[k-1] + prevleng;
        if (k == hi) {
            hi *= 10;
            d++;
        }
        prevleng += d;
        k++;
    }

    int t;
    cin >> t;
    while (t--) {
        int i;
        cin >> i;
        int s = 1, e = 31269;
        ll k, si;
        while (s <= e) {
            k = (s+e)/2;
            if (e == s+1) {
                k++;
            }

            si = ind[k];

            if (e == s) {
                break;
            }

            if (si > i) {
                e = k-1;
            } else {
                s = k;
            }
        }
        int targetj = i-si+1, n, j = 0;
        vector<int> st(10);
        for (n = 1; n < ind[k+1]; n++) {
            int temp = n;
            int sti = 0;
            //cerr << n << " : ";
            do {
                st[sti++] = temp%10;
                temp /= 10;
                //cerr << st[sti-1] << " ";
            } while (temp);
            //cerr << endl;
            if (j+sti < targetj) { 
                j += sti;
            } else {
                cout << st[sti-targetj+j] << endl;
                break;
            }
        }

    }






    return 0;
}
