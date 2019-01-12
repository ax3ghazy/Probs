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

//#define endl '\n'

int n, a, b;
string testcase;
bitset<256> adjMat[256];
int soln[256];
bitset<256> visited;
bool solved;

void solve(int order) {

    if (order == 0) {
        visited[0] = 1;
        soln[0] = 0;
        solve(order+1);
        return;
    }

    if (order == n) {
        if (adjMat[soln[n-1]][0]) {
            solved = true;
        }
        return;
    }

    for (int v = 1; v < n && !solved; v++) {
        if (adjMat[soln[order-1]][v] && !visited[v]) {
            visited[v] = 1;
            soln[order] = v;

            if (order == n-1) {
                if (adjMat[soln[n-1]][0]) {
                    solved = true;
                }
                visited[v] = 0;
                return;
            }

            solve(order+1);

            visited[v] = 0;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (!getline(cin, testcase, '%').eof() && !testcase.empty()) {
        stringstream sin(testcase);
        sin >> n;
        if (n == 1) {
            cout << 1;
        } else if (n == 2) {
            cout << "N";
        } else {

            solved = false;
            memset(adjMat, 0, sizeof(adjMat));
            memset(soln, 0, sizeof(soln));
            visited.reset();

            while (sin >> a >> b) {
                adjMat[a-1][b-1] = 1;
                adjMat[b-1][a-1] = 1;
            }

            solve(0);

            if (solved) {
                for (int i = 0; i < n; i++) {
                    cout << soln[i]+1 << " ";
                }
                cout << soln[0]+1;
            } else {
                cout << "N";
            }
        }
        cout << endl;
    }






    return 0;
}
