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
int H, W, n, T, dimmax, freqmax, dimcur, freqcur;
vector<set<int>> soln;
vector<int> dim;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    T = 0;
    while (cin >> n, n) {
        dimmax = dimcur = -1, freqmax = freqcur = 0;
        soln.clear();
        dim.clear();
        dim.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> dim[i];
        }

        sort(dim.begin(), dim.end());
        for (int i = 0; i < n; i++) {
            if (dim[i] == dimcur) {
                freqcur++;
            } else {
                freqcur = 1, dimcur = dim[i];
            }

            if (freqcur > freqmax) {
                dimmax = dimcur, freqmax = freqcur;
            }
        }
        H = freqmax;
        soln.resize(H);
        for (int i = 0; i < H; i++) {
            soln[i].insert(dimmax);
        }
        for (int i = 0, j = 0; i < n; i++, j = (j+1)%H) {
            if (dim[i] != dimmax) {
                soln[j].insert(dim[i]);
            }
        }

        if (T++)
            cout << endl;
        cout << H << endl;
        for (int i = 0; i < H; i++) {
            auto it = soln[i].rbegin();
            cout << *it; it++;
            for (; it != soln[i].rend(); it++) {
                cout << " " << *it;
            }
            cout << endl;
        }
    }




    return 0;
}
