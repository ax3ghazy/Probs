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
int n, m, cost;
bool solvable;
vector<int> knights(20000), heads(20000);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n >> m, n) {
        cost = 0;
        solvable = (m >= n);
        heads.resize(n);
        knights.resize(m);
        for (int i = 0; i < n; i++) {
            cin >> heads[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> knights[i];
        }

        if (solvable) {
            sort(heads.begin(), heads.end());
            sort(knights.begin(), knights.end());
        }
        auto start = knights.begin();
        for (int i = 0; i < n && solvable; i++) {
            auto it = lower_bound(start, knights.end(), heads[i]);
            if (it == knights.end()) {
                solvable = false;
            } else {
                //cerr << "found " << *it << endl;
                cost += *it;
                start = ++it;
            }
        }

        if (solvable) {
            cout << cost;
        } else {
            cout << "Loowater is doomed!";
        }
        cout << endl;

    }


    return 0;
}
