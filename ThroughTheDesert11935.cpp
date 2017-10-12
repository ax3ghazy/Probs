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
string word;

int leakCount, d0, dt, amount;
double rate, currentMin, current;


int main(){
	ios_base::sync_with_stdio(false);
	while (cin >> d0 >> word >> word){
		current = currentMin = 0.0;
		leakCount = 0;
		if (cin >> amount, !amount)
			break;
		rate = amount/100.0;
		while (cin >> dt >> word){
			int diff = dt-d0;
			current += (rate+leakCount)*diff;
			char beg = word[0];
			if (beg == 'F'){
				cin >> word >> amount;
				rate = amount/100.0;
			}
			else if (beg == 'L')
				leakCount++;
			else if (beg == 'M')
				leakCount = 0;
			else {
				if (current > currentMin)
					currentMin = current;
				if (word[1] == 'a'){
					cin >> word;
					current = 0.0;
				}
				else
					break;
			}
			d0 = dt;
		}
		cout << fixed << setprecision(3) << currentMin << '\n';
	}




	return 0;
}
