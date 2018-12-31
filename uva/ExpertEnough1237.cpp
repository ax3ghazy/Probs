#include <iostream>
#include <sstream>
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
#include <climits>
#include <cmath>
#include <functional>
#include <cstring>
using namespace std;

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



int main(){
	int t, l, h, p, n, q, count;
	ios::sync_with_stdio(false); // faster
	string name, indexed;
	vector<pair<string, ii>> D(10000);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> l >> h;
			D[i] = mp(name, ii(l,h));
		}
		cin >> q;
		while (q--){
			cin >> p;
			count = 0;
			indexed = "UNDETERMINED";
			for (int i = 0; i < n; i++) 
				if (p >= D[i].second.first && p <= D[i].second.second){
					if (!(count++))
						indexed = D[i].first;
					else {
						indexed = "UNDETERMINED";
						break;
					}
				} 	
			cout << indexed << '\n';
		} 
		if (t) cout << '\n';
	}
	

	return 0;
}

