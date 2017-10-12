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

//typedef later
#define ii pair<int,int>
#define iii pair<int,ii>
typedef vector<int> vi;
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue


int t, n, a, A[8][8], R[8], C[8], score, bestScore, cj , minj;

int main(){
	//auto start = chrono::system_clock::now();
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			R[i] = i;
			for (int j = 0; j < n; j++) {
				cin >> a;
				A[i][j] = a;
			}
		}

		bestScore = inf;
		do{
			score = 0;
			for (int i = 0; i < n; i++)
					score += A[i][R[i]];
			if (score < bestScore)
				bestScore = score;
		} while(next_permutation(R,R+n));
		cout << bestScore << '\n';
	}

	/*
	auto end = chrono::system_clock::now();
	auto dur = chrono::duration_cast<chrono::milliseconds> (end-start);
	cout << "time = " << dur.count() << '\n';
	*/

	return 0;
}

