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
int route[20005], S, b;

void solve(int r) {
  int sum = 0, soln = 0, s = 1, solns, solne;
  for (int e = 1; e <= S-1; ++e) {
    int a = route[e];
    if (sum + a >= 0) {
      sum += a;
    } else {
      sum = 0;
      s = e+1;
    }
    if ((sum > soln) || (sum == soln && e-s > solne-solns)) {
      soln = sum;
      solns = s, solne = e;
    }
  }
  if (soln != 0) {
    cout << "The nicest part of route " << r << " is between stops " << solns
         << " and " << solne+1 << endl;
  } else {
    cout << "Route " << r << " has no nice parts" << endl;
  }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> b;
    for (int r = 1; r <= b; r++){
      cin >> S;
      for (int i = 1; i <= S-1; ++i) {
        cin >> route[i];
      }
      solve(r);
    }

    return 0;
}
