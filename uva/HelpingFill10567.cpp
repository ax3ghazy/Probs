#include <iostream>
#include <iomanip>
#include <sstream>
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
#define eps 1e-9
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

char c;
bool possible;
int i, q, s, e;
int db[52][1000000] = {0};
int ind[52] = {0};
int of (char a){
	if (islower(a))
		return a-'a';
	else
		return a-'A'+26;
}
int main(){
	ios_base::sync_with_stdio(false);
	i = 1;
	while (cin.get(c), c != '\n'){
		int j = of(c);
		db[j][ind[j]++] = i++;
	}
	cin >> q;
	cin.ignore();
	while (q--){
		possible = true;
		i = 1;
		s = e = 0;
		while (cin.get(c), c != '\n'){ //
			if (possible){
				int j = of(c), *st = db[j], *sum = st+ind[j];
				int* it = lower_bound(st, sum, i+1);
				if (it == sum)
					possible = false;
				else{
					i = (*it);
					if (!s)
						s = i;
				}
			}
		}
		if (!possible)
			cout << "Not matched\n";
		else
			cout << "Matched " <<  s-1 << ' ' << i-1 << '\n';
	}



	return 0;
}
