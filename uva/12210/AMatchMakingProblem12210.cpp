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

int b, s, cnt, age, T;
multiset<int> A, B;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    T = 1;
    while (cin >> b >> s, b) {
        cnt = 0;
        A.clear();
        B.clear();
        for (int i = 0; i < b; i++) {
            cin >> age;
            A.insert(age);
        }
        for (int i = 0; i < s; i++) {
            cin >> age;
            B.insert(age);
        }

        for (auto it = A.rbegin(); it != A.rend() && !B.empty(); it++) {
            int n = *it, diff;
            auto bit = B.lower_bound(n), tempit = bit;
            tempit--;

            diff = (*bit)-n;
            cnt++;
            if (bit == B.end() || (bit != B.begin() && diff > n-(*tempit))) {
                //cerr << "marrying " << n << " to " << *tempit << endl;
                B.erase(tempit);
            } else {
                //cerr << "marrying " << n << " to " << *bit << endl;
                B.erase(bit);
            }
        }

        cout << "Case " << T++ << ": ";
        cout << b-cnt;
        if (b-cnt > 0) {
            cout << ' ' << *A.begin();
        }
        cout << endl;
    }






    return 0;
}
