#include <bits/stdc++.h>
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


int main(){
	ios_base::sync_with_stdio(false);
	int k, m;
	while (cin >> k, k){
		cin >> m;

		vi Mrcnt(m);
		vector<unordered_set<int>> M(m);
		vi crs(k);

		for (int i = 0; i < k; i++)
			cin >> crs[i];

		for (int i = 0; i < m; i++){
			int c, r;
			cin >> c >> r;
			Mrcnt[i] = r;
			for (int j = 0; j < c; j++){
				int crsnum;
				cin >> crsnum;
				M[i].insert(crsnum);
			}
		}
		
		bool no = false;
		if (m != 0){
			for (int j = 0; j < k; j++){
				for (int i = 0; i < m; i++)
					if (M[i].count(crs[j]))
						Mrcnt[i]--;
			}
			for (int j = 0; j < m && !no; j++)
				if (Mrcnt[j] > 0)
					no = true;
		}
		if (no)
			cout << "no\n";
		else 
			cout << "yes\n";
	}

	return 0;
}
