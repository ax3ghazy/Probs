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

int t, n, rungs[100000], diffs[100000], temp, tempPrev, ndiff, s, e, m;

int remainingK (int k){
	int h = 0, diff, rung;
	for (size_t i = 0; i < n; i++) {
		rung = rungs[i];
		diff = rung-h;
		if ( diff > k)
			return -1;
		if (diff == k)
			k--;
		h = rung;
	}
	return k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (size_t j = 1; j <= t; j++){
		cin >> n >> tempPrev; rungs[0] = tempPrev;

		multiset<int> diffset;
		diffset.insert(tempPrev);
		for (int i = 1; i < n; i++){
			cin >> temp;
			rungs[i] = temp;
			diffset.insert(temp-tempPrev);
			tempPrev = temp;
		}
		copy(diffset.begin(), diffset.end(), diffs);
		ndiff = diffset.size();
		s = diffs[ndiff-1], e = s+n;
		temp = e;
		while (s <= e){
			m = (s+e)/2;
			tempPrev = remainingK(m);
			if (tempPrev >= 0){
				e = m-1;
				if (m < temp)
					temp = m;
			}
			else
				s = m+1;
		}
		cout << "Case " << j << ": " << temp << '\n';
	}




	return 0;
}
