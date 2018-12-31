#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
#define EPS 1e-9

#define pb push_back

#define isOn(S, j) ((S) & (1 << (j)))
#define setBit(S, j) (S |= (1 << (j)))
#define clearBit(S, j) (S &= ~(1 << (j)))
#define toggleBit(S, j) (S ^= (1 << (j)))
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
	for (int i = 1; i <= N; i++){
		int R, C; cin >> C >> R;
		int Qtot = C-R;
		cout << "Case #" << i << ":";
		if (Qtot == 0)
			cout << ' ' << 0 << '\n';
		else {
			set<int> divisors;
			if (1 > R)
				divisors.insert(1);
			if (Qtot > R)
				divisors.insert(Qtot);
			for (int d = 2; d*d <= Qtot; d++){
				if (Qtot%d == 0){
					int quot = Qtot/d;
					if (quot > R){
						divisors.insert(quot);
						if (d > R)
							divisors.insert(d);
					} else
						break;
				}
			}
			for (auto &d : divisors)
				cout << ' ' << d;
			cout << '\n';
		}
	}

	return 0;
}
