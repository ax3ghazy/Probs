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
int A[10000], N, M, st;

int main(){
	ios_base::sync_with_stdio(false);
	while (cin >> N){
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cin >> M;

		sort(A, A+N);
		st = lower_bound(A, A+N, ceil(M/2.0))-A;
		for (int i = st+1; i < N && A[i] == A[st]; i++, st++);
		int *o, elem, diff;
		for (int i = st; i < N; i++) {
			elem = A[i];
			diff = M-elem;
			o = lower_bound(A, A+st,diff);
			if (*o == diff && o != A+st)
				break;
		}
		cout << "Peter should buy books whose prices are " << *o << " and " << elem << ".\n\n";
	}




	return 0;
}
