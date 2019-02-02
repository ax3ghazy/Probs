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

int T, N, D, mx;

bitset<105> big;
vector<int> rocks;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    rocks.resize(105);
    cin >> T;
    for (int t=1; t <= T; t++) {
        cin >> N >> D;
        mx = 0;
        big.reset();
        rocks.clear();

        rocks.pb(0); big[0] = true;
        for (int i = 1; i <= N; i++) {
            char t, _; int x;
            cin >> t >> _ >> x;
            rocks.pb(x);
            big[i] = (t == 'B');
        }
        rocks.pb(D); big[N+1] = true;

        bool skip = true;
        int last = 0;
        for (int i = 1; i <= N+1; i++) {
            if (big[i]) {
                mx = max(mx, rocks[i]-last);
                last = rocks[i];
            } else {
                if (!skip) {
                    mx = max(mx, rocks[i]-last);
                    last = rocks[i];
                }
                skip = !skip;
            }
        }

        last = D;
        for (int i = N; i >= 0; i--) {
            if (big[i]) {
                mx = max(mx, last-rocks[i]);
                last = rocks[i];
            } else {
                if (!skip) {
                    mx = max(mx, last-rocks[i]);
                    last = rocks[i];
                }
                skip = !skip;
            }
        }

        cout << "Case " << t << ": " << mx << endl;

    }


    return 0;
}
