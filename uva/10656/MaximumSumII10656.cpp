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

int N;
vector<int> A(1000);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N, N) {
        bool first = true;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (A[i]) {
                if (!first) {
                    cout << " ";
                } else {
                    first = false;
                }
                cout << A[i];
            }
        }
        if (first)
            cout << 0;
        cout << endl;
    }






    return 0;
}
