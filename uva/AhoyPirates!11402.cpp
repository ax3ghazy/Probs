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


typedef vector<int> vi;


class segTree{ //min
	private:
		vi st;
	  	vector<char> lazy;
	  	string A;
		int n;
		int lefti(int i) {return (i<<1);}
		int righti(int i) {return (i<<1)+1;}
		
		void build (int i, int L, int R){
			if (L==R)
				st[i] = (A[L]=='1');
			else{
				int avgSum = (L+R)/2;
				build(lefti(i), L, avgSum);
				build(righti(i), avgSum+1, R);
				st[i] = st[lefti(i)] + st[righti(i)];
			}
		}
		
		int rmq (int i, int L, int R, int s, int e){
			if(lazy[i]){
				apply (i, L, R, lazy[i]);

				if (L != R){
					if (lazy[i] != 'I'){
						lazy[lefti(i)] = lazy[i];
						lazy[righti(i)] = lazy[i];
					}
					else{
						if (!lazy[lefti(i)])
							lazy[lefti(i)] = lazy[i];
						else if (lazy[lefti(i)] != 'I')
							lazy[lefti(i)] = 'F' - (lazy[lefti(i)] - 'E');
						else
							lazy[lefti(i)] = '\0';

						if (!lazy[righti(i)])
							lazy[righti(i)] = lazy[i];
						else if (lazy[righti(i)] != 'I')
							lazy[righti(i)] = 'F' - (lazy[righti(i)] - 'E');
						else
							lazy[righti(i)] = '\0';
					}
				}
				lazy[i] = '\0';
			}

			if (s > R || e < L) return 0;

			if (R <= e && L >= s) return st[i];
			
			int avgSum = (L+R)/2;
			return rmq (lefti(i), L, avgSum, s, e)
				  + rmq (righti(i), avgSum+1, R, s, e);
		}
		
		int updatePoint (int i, int L, int R, int se, char val){
			if (se > R || se < L) return st[i];
			
			if (L == R && L == se){
				A[se] = val;
				return (st[i] = val=='1'); 
			}

			int avgSum = (L+R)/2;
			return (st[i] = (updatePoint(lefti(i), L, avgSum, se, val)
				  + updatePoint (righti(i), avgSum+1, R, se, val)));
		}

		void apply(int i, int L, int R, char val){
			switch (val){
				case 'F':
					st[i] = R-L+1;
					break;
				case 'E':
					st[i] = 0;
					break;
				default:
					st[i] = R-L+1-st[i];
			}
		}

		void updateRange(int i, int L, int R, int s, int e, char val){
			if(lazy[i]){
				apply (i, L, R, lazy[i]);

				if (L != R){
					if (lazy[i] != 'I'){
						lazy[lefti(i)] = lazy[i];
						lazy[righti(i)] = lazy[i];
					}
					else{
						if (!lazy[lefti(i)])
							lazy[lefti(i)] = lazy[i];
						else if (lazy[lefti(i)] != 'I')
							lazy[lefti(i)] = 'F' - (lazy[lefti(i)] - 'E');
						else
							lazy[lefti(i)] = '\0';

						if (!lazy[righti(i)])
							lazy[righti(i)] = lazy[i];
						else if (lazy[righti(i)] != 'I')
							lazy[righti(i)] = 'F' - (lazy[righti(i)] - 'E');
						else
							lazy[righti(i)] = '\0';
					}
				}
				lazy[i] = '\0';
			}
			
			if (s > R || e < L)	return;
			
			if (R <= e && L >= s){
				apply (i, L, R, val);
			
				if (L != R){
					if (val != 'I'){
						lazy[lefti(i)] = val;
						lazy[righti(i)] = val;
					}
					else {
						if (!lazy[lefti(i)])
							lazy[lefti(i)] = val;
						else if (lazy[lefti(i)] != 'I')
							lazy[lefti(i)] = 'F' - (lazy[lefti(i)] - 'E');
						else
							lazy[lefti(i)] = '\0';

						if (!lazy[righti(i)])
							lazy[righti(i)] = val;
						else if (lazy[righti(i)] != 'I')
							lazy[righti(i)] = 'F' - (lazy[righti(i)] - 'E');
						else
							lazy[righti(i)] = '\0';
					}
				}
				return;
			}

			int avgSum = (L+R)/2;
			updateRange(lefti(i), L, avgSum, s, e, val);
			updateRange(righti(i), avgSum+1, R, s, e, val);

			st[i] = st[lefti(i)] + st[righti(i)];
		}
	
	
	
	public:
		segTree (const string& data){
					A = data;
					n = data.size();
					st.assign(4*n+1,0);
					lazy.assign(4*n+1,'\0');
					build(1, 0, n-1);
				}
		int roq (int s, int e){
					return rmq(1, 0, n-1, s, e);
				}
		int updatePoint (int se, char val){
					updatePoint(1, 0, n-1, se, val);
				}
		void updateRange(int s, int e, char val){
					updateRange(1, 0, n-1, s, e, val);
		}
};


int main(){
	int t, m, conc, s, e, q;
	string pirates, part;
	char instruction;
	sdf(t);
	for (int i = 0; i < t; i++){
		printf("Case %d:\n", i+1);
		q = 1;
		sdf(m);
		pirates = "";
		while (m--){
			cin >> conc >> part;
			while (conc--)
				pirates += part;
		}
		sdf(m);
		segTree tree(pirates);
		while (m--){
			cin >> instruction >> s >> e;
			if (instruction != 'S')
				tree.updateRange(s, e, instruction);
			else
				printf("Q%d: %d\n", q++, tree.roq(s, e));
		}

	
	
	}

	return 0;
}

