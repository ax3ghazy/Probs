#include <iostream>
#include <iomanip>
#include <bitset>
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

int n, takenSet[10], patterns[10],  working[10];
char c;
map<int, int> mapping;

int main(){ //no use of backtracking
	ios_base::sync_with_stdio(false);
	mapping[0x7e] = 0;
	mapping[0x30] = 1;
	mapping[0x6d] = 2;
	mapping[0x79] = 3;
	mapping[0x33] = 4;
	mapping[0x5b] = 5;
	mapping[0x5f] = 6;
	mapping[0x70] = 7;
	mapping[0x7f] = 8;
	mapping[0x7b] = 9;

	while (cin >> n, n){
		fill(takenSet, takenSet+10, 0);
		for (int j = 0; j < n; j++) { //generate sets
			working[j] = 0;
			patterns[j] = 0;
			for (int i = 0; i < 7; i++)
				if (cin >> c, c == 'Y'){
					setBit(patterns[j],6-i);				
					for (int k = 0; k < j; k++)
						setBit(working[k],6-i);
				}
		}
		for (int j = 0; j < n; j++) {
			for (const pair<int, int>& mapped : mapping){
				bool valid = true;
				for (int i = 0; i < 7 && valid; i++)
					if ((isOn(patterns[j], i) && !isOn(mapped.first, i)) || (isOn(working[j],i) && !isOn(patterns[j],i) && isOn(mapped.first,i)))
						valid = false;
				if (valid)
					setBit(takenSet[j], mapped.second);			
			}
		}

		bool match = true;
		for (int i = 0; i < n-1 && match; i++){
			takenSet[i+1] = (takenSet[i]>>1)&takenSet[i+1];
			if (!takenSet[i+1])
				match = false;
		}
		if (match)
			cout << "MATCH";
		else 
			cout << "MISMATCH";
		cout << '\n';
	}

	return 0;
}
