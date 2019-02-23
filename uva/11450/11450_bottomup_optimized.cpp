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

int G, M, modelPrices[25][25];
bool dp[2][205];
int prv, cur;

void solve() {
    for (int model = 1; model <= modelPrices[0][0]; model++) {
        int price = modelPrices[0][model];
        if (M - price >= 0) {
            dp[prv][M-price] = true;
        }
    }
    for (int g = 1; g < G; g++) {
        for (int m = 0; m <= M; m++) {
            dp[cur][m] = false;
            if (dp[prv][m] == true) {
                for (int model = 1; model <= modelPrices[g][0]; model++) {
                    int price = modelPrices[g][model];
                    if (m - price >= 0) {
                        dp[cur][m-price] = true;
                    }
                }
            }
        }
        swap(prv, cur);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
        memset(dp, false, 205);
		cin >> M >> G;
        prv = 0, cur = 1;
		for (int i = 0; i < G; i++) {
			int K; cin >> K;
			modelPrices[i][0] = K;
			for (int j = 1; j <= K; j++)
				cin >> modelPrices[i][j];
		}
        solve();
		int m;
        for (m = 0; m <= M && !dp[prv][m]; m++);

		if (m == M+1)
			cout << "no solution";
		else
			cout << M-m;
		cout << endl;
	}

	return 0;
}

