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
    char start, end; 
    int n;
    ll startp = 0, endp = 0;
    ll solns;
    cin >> n;
    string s;
    cin >> s;
    start = s[0], end = s[n-1];
    for (int i = 0; i < n && s[i] == start; i++) {
        startp++;
    }
    for (int i = n-1; i >= 0 && s[i] == end; i--) {
        endp++;
    }
    if (start == end && startp + endp > n) {
        solns = startp*(startp+1)/2;
    } else if (start != end) {
        solns = 1+1+1+startp-1+endp-1;
    } else {
        solns = (startp+1)*(endp+1);
    }

    cout << solns%998244353L << endl;
    
    return 0;
}
