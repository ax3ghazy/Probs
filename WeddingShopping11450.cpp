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

int G,M, memo[201][20], modelPrices[20][21];

int shop (int money, int g){
	//cout << "state: " << money << ',' << g << '\n';
	if (money < 0)
	   	return -500;

	if (g == G)
		return M-money;

	if (money == 0)
		return -500;

	int &ans = memo[money][g];
	if (ans != -1)
		return ans;
	int lim = modelPrices[g][0];
	for (int model = 1; model <= lim; model++)
		ans = max(ans, shop(money-modelPrices[g][model], g+1));
	return ans;
}




int main(){
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while (T--){
		cin >> M >> G;
		for (int i = 0; i < G; i++){
			int K; cin >> K;
			modelPrices[i][0] = K;
			for (int j = 1; j <= K; j++)
				cin >> 	modelPrices[i][j];
		}
		memset(memo, -1, sizeof(memo));
		int ans = shop(M, 0);
		if (ans >= 0)
			cout << ans;
		else
			cout << "no solution";
		cout << '\n';
	}



	
	return 0;
}

