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
#define rmOne(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

//typedef later
#define ii pair<int,int>
#define iii pair<int,ii>
typedef vector<int> vi;
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue

class fenwickTree {
	private:
		vi ft;
		inline void next (int& i){i += rmOne(i);}
		inline void parent(int& i) { i &= ~rmOne(i);}

	public:
		fenwickTree (int n){
			ft.assign(n+1, 0);
		}

		void update (int i, int diff){
			i++;
			while (i<ft.size()){
				ft[i] += diff;
				next(i);
			}
		}
		
		int rsq (int b){
			b++;
			int sum = 0;
			while (b){
				sum += ft[b];
				parent(b);
			}
			return sum;
		}

		int rsq (int a, int b){
			return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
		}

};


int main() {
	ios_base::sync_with_stdio(false);
	long long n, count = 0, a, b;
       	cin >> n;
	fenwickTree ft(n);
	map<int, vi> aMap;
	for (int i = 0; i < n; i++) {
		cin >> a;
		aMap[a].push_back(i);
	}
	a = 0;
	int rem = n, i, vsize, iend, temp;
	for (const auto& p : aMap){
		const vi& indices = p.second;
		vsize = indices.size();

		int s = 0, e = vsize-1;
		i = -1;
		while (s<=e){
			int m = (s+e)/2;
			temp = indices[m];
			temp += ft.rsq(temp);
			if (temp >= a){
				i = m;
				e = m-1;
			}
			else
				s = m+1;
		}
		if (i == -1)
			i = 0;

		iend = i;
		do {
			temp = indices[i];

			b = temp + ft.rsq(temp);
			if (b>=a)
				count += b-a+1;
			else
				count += rem-a+b+1;

			ft.update(temp, -1);
			if (--rem)
				a = b%rem;
			i = (i+1)%vsize;
		} while (i != iend);
	}
	cout  << count << '\n';
	
	


	



	return 0;
}
