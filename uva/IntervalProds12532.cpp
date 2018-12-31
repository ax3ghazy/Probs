#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cctype>
#include <cmath>
#include <functional>
#include <cstring>
using namespace std;

#define mp(A,B) make_pair(A,B)
#define mxstr 100000000
#define sdf(n) scanf("%d",&n)
#define sds(a) scanf("%s", a)
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

#define rmOne(S) (S & (-S))
class fenwickTree {
	private:
		vi ft;
		void next (int& i){i += rmOne(i);}
		void parent(int& i) { i &= ~rmOne(i);}

	public:
		fenwickTree (int n){
			ft.assign(n+1, 0);
		}

		void updateDiff (int i, int diff){
			while (i<ft.size()){
				ft[i] += diff;
				next(i);
			}
		}

		void update(int i, int v, int old = 0){
			if (old != v)
				updateDiff (i, v-old);
		}

		int rsq (int b){
			int sum = 0;
			while (b){
				sum += ft[b];
				parent(b);
			}
			return sum;
		}

		int rsq (int a, int b){
			return rsq(b) - rsq(a-1);
		}

};


int main() {              
	int n, k, a, v, negN, zeroN;
	char inst;
	while (sdf(n) == 1 && n){
		sdf(k);
		fenwickTree zero(n);
		fenwickTree neg(n);
		vector<int> all(n+1);
		for (int i = 1; i <= n; i++) {
			sdf(a);
			all[i] = a;
			if (!a) zero.update(i, 1);
			else if (a < 0) neg.update(i, 1);
		}
		while (k--){
			cin >> inst;
			sdf(a); sdf(v);
			if (inst == 'C'){
				negN = all[a] < 0, zeroN = !all[a];
				all[a] = v;
				if (!v) {
					zero.update(a, 1, zeroN);
					neg.update(a, 0, negN);
				}
				else if (v < 0) {
					neg.update(a, 1, negN);
					zero.update(a, 0, zeroN);
				}
				else{
					neg.update(a, 0, negN);
					zero.update(a, 0, zeroN);
				}
			}
			else{
				negN = neg.rsq(a,v), zeroN = zero.rsq(a,v);
				if (zeroN) printf("0");
				else if (negN&1) printf("-");
				else printf("+");
			}
		}
		pendl();
	}
	return 0;
}

