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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int on_count[2005];
    bitset<2005> switches[2005];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char on;
            cin >> on;
            //cerr << "read: " << on << endl;
            switches[i][j] = (on == '1');
            if (switches[i][j]) {
                on_count[j]++;
            }
        }
    }
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if(on_count[j] - switches[i][j] == 0) {
                break;
            }
        }
        if (j == m) {
            break;
        }
    }

    if (i < n) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
