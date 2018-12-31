#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
#define EPS 1e-9

#define pb push_back

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)


typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

ll date2day (ll d, ll m, ll y){
	m = (m+9)%12;
	y = y-m/10;
	return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 );
}

void day2date (ll g, ll &dd, ll &mm, ll&y){
	y = (10000*g + 14780)/3652425;
	ll ddd = g - (365*y + y/4 - y/100 + y/400);
	if (ddd < 0){
		y = y - 1;
		ddd = g - (365*y + y/4 - y/100 + y/400);
	}
	ll mi = (100*ddd + 52)/3060;
	mm = (mi + 2)%12 + 1;
	y = y + (mi + 2)/12;
	dd = ddd - (mi*306 + 5)/10 + 1;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll d, m, y, n;
	while (cin >> n >> d >> m >> y, (n || m || d || y)){
		ll g;
		g = date2day(d,m,y);
		g += n;
		day2date(g, d, m, y);
		cout << d << ' ' << m << ' ' << y << '\n';
	}
	return 0;
}
