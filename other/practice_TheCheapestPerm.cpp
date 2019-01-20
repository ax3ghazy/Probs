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

int n;
int mn = infint;
int A[10][10];
vector<int> pi, p;

inline int cost() {
    int sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += A[pi[i]][pi[i+1]];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    pi.resize(n);
    for (int i = 0; i < n; i++) {
        pi[i] = i+1;
    }
    A[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    do {
        int cur_cost = cost();
        if (cur_cost < mn) {
            mn = cur_cost;
            p.assign(pi.begin(), pi.end());
        }
    } while (next_permutation(pi.begin(), pi.end()));

    cout << p[0];
    for (int i = 1; i < n; i++) {
        cout << " " << p[i];
    }
    cout << endl;






    return 0;
}
