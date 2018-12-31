#include <cstdio>
#include <set>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

struct comp {
	bool operator() (const int& lhs, const int& rhs){
		return lhs > rhs;
	}
};


int main() {
	int t, bn, sg, sb,s;
	scanf("%d",&t);
	while (t--){
		multiset<int, comp> g,b;
		scanf("%d %d %d",&bn, &sg, &sb);
		vector<pair<int,bool>> bf(1000000);
		int mx = 0;
		while (sg--) {
			scanf("%d",&s);
			g.insert(s);
		}
		while (sb--) {
			scanf("%d",&s);
			b.insert(s);
		}
		while (!b.empty() && !g.empty()){
			int i;
			for (i = 0; i < bn && !b.empty() && !g.empty(); i++){
				int soldB = *b.begin(), soldG =*g.begin();
				b.erase(b.begin());
				g.erase(g.begin());
				bf[i] = pair<int,bool>(abs(soldB-soldG), soldB > soldG);
			}
			for (int j = 0; j < i; j++){
				if (bf[j].first){
					if (bf[j].second) b.insert(bf[j].first);
					else g.insert(bf[j].first);
				}
			}
		}
		if (b.empty() && g.empty()) printf("green and blue died\n");
		else if (g.empty()) {
			printf("blue wins\n");
			for (multiset<int,comp>::iterator it = b.begin(); it != b.end(); it++)
				printf("%d\n", *it);
		}
		else {
			printf("green wins\n");
			for (multiset<int,comp>::iterator it = g.begin(); it != g.end(); it++)
				printf("%d\n", *it);
		}
		if (t) printf("\n");
	}
	
	
	return 0;
}
