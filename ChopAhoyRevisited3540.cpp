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

#define D(c) (c-'0')

char str[30];
int n;
int memo[25][225];

int backtrack(int i, int prevsum = 0){

	if (i == n)
		return 1;

	int &cnt = memo[i][prevsum];
	if(cnt != -1)
		return cnt;
	cnt = 0;

	int sum = 0;
	for (int j = i; j < n; j++){
		sum += D(str[j]);
		//cout << "sum : " << sum << '\n';
		if (sum >= prevsum)
			cnt += backtrack(j+1, sum);
	}
	return cnt;
}




int main(){
	ios_base::sync_with_stdio(false);
	int t = 1;
	while (cin >> str, str[0] != 'b'){
		n = strlen(str);
		memset(memo, -1, sizeof(memo));
		cout << (t++) << ". " << backtrack(0, 0) << '\n';


	}





	return 0;
}
