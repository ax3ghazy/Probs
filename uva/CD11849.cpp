#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int m, n, shared = 0,cd, i;
	int* end;
	int col1[1000005], col2[1000005], inter[2000010];
	while (scanf("%d %d", &m, &n), m || n){
		for (i = 0; i < m; ++i){
			scanf("%d",&cd);
			col1[i] = cd;
		}
		for (i = 0; i < n; ++i){
			scanf("%d",&cd);
			col2[i] = cd;
		}
		end = set_intersection(col1, col1+m, col2, col2+n, inter); //for sorted ranges
		printf("%d\n",end-inter);

	}
	return 0;
}

////another:
/*

#include <set>
#include <cstdio>
using namespace std;

int main() {
	int m, n, shared = 0,cd;
	set<int> collection;
	while (scanf("%d %d", &m, &n), m || n){
		while (m--){
			scanf("%d",&cd);
			if (collection.count(cd)) shared++;
			else collection.insert(cd);
		}
		while (n--){
			scanf("%d",&cd);
			if (collection.count(cd)) shared++;
			else collection.insert(cd);
		}
		printf("%d\n",shared);
		
		collection.clear();
		shared = 0;
	}
	return 0;
}


*/

