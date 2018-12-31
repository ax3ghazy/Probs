#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
#define EPS 1e-9

#define pb push_back

#define isOn(S, j) ((S) & (1 << (j)))
#define setBit(S, j) ((S) |= (1 << (j)))
#define clearBit(S, j) ((S) &= ~(1 << (j)))
#define toggleBit(S, j) ((S) ^= (1 << (j)))
#define lowBit(S) ((S) & (-(S)))
#define setAll(S, n) (S = (1 << (n)) - 1)
#define pque priority_queue 

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	while (N--){
		int n, k; cin >> n >> k;
		cout << (k^(k>>1)) << '\n';
	}

	return 0;
}
