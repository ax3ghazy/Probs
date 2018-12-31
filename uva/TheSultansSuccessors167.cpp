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

const int n = 8;
int mx;
bitset<n> row_occ;
bitset<2*n-1> dia1_occ, dia2_occ;
int board[n][n];
int row[n];


void backtrack(int c) {
    if (c == n) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += board[row[i]][i];
        }
        if (s > mx) {
            mx = s;
           // cout << mx << ": ";
           // for (int i = 0; i < n; i++) {
           //     cout << row[i] << ' ';
           // }
           // cout << endl;

        }
        return;
    }

    for (int r = 0; r < n; r++)  {
        if (!row_occ[r] && !dia1_occ[r-c+n-1] && !dia2_occ[r+c]) {
            row[c] = r;
            row_occ[r] = dia1_occ[r-c+n-1] = dia2_occ[r+c] = 1;
            backtrack(c+1);
            row_occ[r] = dia1_occ[r-c+n-1] = dia2_occ[r+c] = 0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while (k--) {
        mx = -1;
        row_occ.reset();
        dia1_occ.reset();
        dia2_occ.reset();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        backtrack(0);
        cout << setw(5) << mx << endl;
    }

    return 0;
}
