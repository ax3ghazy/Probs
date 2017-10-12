#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <ctime>
#include <chrono> //C++11
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <functional>
#include <cstring>
using namespace std;

#define inf 0x7fffffff //32-bit int
#define ninf 0x80000000
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

//typedef later
#define ii pair<int,int>
#define iii pair<int,ii>
typedef vector<int> vi;
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue
int n, m, belt[1000000], s, e, mid, temp, best, cnt;
bool perfect;


int filled (int cap){
	int mcand = 1, item, curr = 0;
	perfect = false;
	for (int i = 0; i < n; i++){
		item = belt[i];
		if (item + curr > cap){
			mcand++;
			curr = 0;
		}
		curr += item;
		if (curr == cap)
			perfect = true;
		if (mcand > m)
			break;
	}

	return mcand;
}

int main(){
	ios_base::sync_with_stdio(false);
	while (cin >> n >> m ){
		s = e = 0;
		for (int i = 0; i < n; i++){
			cin >> temp;
			belt[i] = temp;
			if (temp > s)
				s = temp;
			e += temp;
		}

		best = e;
		while (s <= e){
			mid = (s+e)/2;
			temp = filled(mid);
			/*cout << mid << ' ';
			cout << temp << '\n';
			cout << s << ' ' << e << '\n';
			cin >> cnt;*/
			if (temp > m){
				s = mid+1;
				continue;
			}
			else if (perfect && mid < best)
				best = mid;
			e = mid-1;
		}
		cout << best << '\n';
	}

	return 0;
}
