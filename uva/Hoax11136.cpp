#include <cstdio>
#include <set>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	long long n, k, cost, bill, t = 0;
	multiset<int> urn;
	multiset<int>::iterator it1, it2;
	while (scanf("%lld",&n), n){
		while (n--){
			scanf("%lld",&k);
			while(k--) {
				scanf("%lld",&bill);
				urn.insert(bill);
			}
			it1 = urn.begin();
			it2 = urn.end(); it2--;
			cost += *it2 - *it1;
			urn.erase(it1);
			urn.erase(it2);
		}
		printf("%lld\n", cost);
		urn.clear();
		cost = 0;
	}
	
	
	return 0;
}
