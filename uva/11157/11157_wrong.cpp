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

int T, N, D, st;

struct comp {
    bool operator() (const ii &a, const ii &b) const {
        return (a.second-a.first)>(b.second-b.first);
    }
};


multiset<ii, comp> jumps;
vector<int> S;

bool goToBest(ii jump) {
    int s = jump.first, e = jump.second;
    double m = (s+e)/2.0;
    auto itg = lower_bound(S.begin(), S.end(), m, less<double>());
    auto its = lower_bound(S.rbegin(), S.rend(), m, greater<double>());
    vector<int>::iterator it = S.end();

    if (itg != S.end()) {
        if (*itg  < e) {
            it = itg;
        }
    }
    if (its != S.rend()) {
        if (*its > s && (itg == S.end() || m-(*its) < (*itg)-m)) {
            it = its.base();
            it--;
        }
    }
    if (it != S.end()) {
        cerr << "erasing" << *it << endl;
        jumps.insert(ii(s, *it));
        jumps.insert(ii(*it, e));
        S.erase(it);
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t=1; t <= T; t++) {
        jumps.clear();
        S.clear();

        cin >> N >> D;
        st = 0;
        for (int i = 0; i < N; i++) {
            char t, _; cin >> t >> _;
            int x; cin >> x;
            if (t == 'B') {
                jumps.insert(ii(st, x)); jumps.insert(ii(st, x));
                st = x;
            } else {
                S.pb(x);
            }
        }
        jumps.insert(ii(st,D)); jumps.insert(ii(st,D));

        //cerr << "jumps: " << endl;
        //cerr << endl;

        bool change;
        do {
            change = false;
            if (goToBest(*jumps.begin())) {
                jumps.erase(jumps.begin());
                change = true;
            }
        } while (change);

        for (auto p : jumps) {
            cerr << p.first << "->" << p.second << " (" << p.second-p.first << ")" << endl;
        }

        cout << "Case " << t << ": " << (jumps.begin()->second)-(jumps.begin()->first) << endl;
        cout << "Case " << t << ": " << (jumps.begin()->second) << " <= " << (jumps.begin()->first) << endl;

    }






    return 0;
}
