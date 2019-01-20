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

class FenwickTree {
    private:
        vector<int> T; //T[i] == sum A[g(i)...i] ;
        int n;

        //g(i) = i & (i+1)
        inline int boundary_g(int i) {
            return i&(i+1);
        }

        //h(j) = next j such that g(j) <= i <= j
        inline int nextj_h(int j) {
            return j|(j+1);
        }

    public:
        FenwickTree(int n) {
            T.assign(n, 0);
            this->n = n;
        }


        void add(int i, int delta) {
            int j = i;
            for (; j < n; j = nextj_h(j)) {
                T[j] += delta;
            }
        }

        int sum(int r) {
            int res = 0;
            for (; r >= 0; r = boundary_g(r)-1) { //nested loops for multidimensions!
                res += T[r];
            }
            return res;
        }

        int sum(int l, int r) {
            return sum(r)-sum(l-1);
        }

        void set(int i, int new_val) {
            int Ai = sum(i,i);
            add(i, new_val - Ai);
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, a, b;
    string query;
    int T = 0;
    while (cin >> N, N) {
        if (T) {
            cout << endl;
        }

        cout << "Case " << ++T<< ':' << endl;

        FenwickTree potmeters(N+1);
        for (int i = 1; i < N+1; i++) {
            int R; cin >> R;
            potmeters.add(i, R);
        }

        while (cin >> query, query[0] != 'E') {
            cin >> a >> b;
            if (query[0] == 'M') {
                    cout << potmeters.sum(a, b);
            } else {
                potmeters.set(a, b);
            }
        }
    }

    return 0;
}
