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




class segTree{ //min
	private:
		vi st, A;
		int n;
		int lefti(int i) {return (i<<1);}
		int righti(int i) {return (i<<1)+1;}
		
		void build (int i, int L, int R){
			if (L==R)
				st[i] = L;
			else{
				int avgSum = (L+R)/2;
				build(lefti(i), L, avgSum);
				build(righti(i), avgSum+1, R);
				int left = st[lefti(i)], right = st[righti(i)];
				st[i] = A[left] < A[right]? right : left;
			}
		}
		
		int rmq (int i, int L, int R, int s, int e){
					if (s > R || e < L) return -1;
					if (R <= e && L >= s) return st[i];
					
					int avgSum = (L+R)/2;
					int left = rmq (lefti(i), L, avgSum, s, e);
					int right = rmq (righti(i), avgSum+1, R, s, e);
					
					if (left == -1) return right;
					if (right == -1) return left;
					return (A[left] < A[right]? right : left);
				}
		
		int updatePoint (int i, int L, int R, int se, int val){
					if (se > R || se < L) return st[i];
					
					if (L == R && L == se){
						A[se] = val;
						return (st[i]=L); //in case we add new elements
					}
					int avgSum = (L+R)/2;
					int left = updatePoint (lefti(i), L, avgSum, se, val);
					int right = updatePoint(righti(i), avgSum+1, R, se, val);
					return (st[i] = A[left] < A[right]? right : left);
						
				}
	
	
	
	public:
		segTree (const vi& data, int s, int size){
					A.assign(data.begin()+s, data.begin()+size);
					n = A.size();
					st.assign(4*n+1,-1);
					build(1, 0, n-1);
				}
		int rmq (int s, int e){
					return rmq(1, 0, n-1, s, e);
				}
		int updatePoint (int se, int val){
					updatePoint(1, 0, n-1, se, val);
				}
	
};

int n, q, a, j, c, s, e;
vi A(100005),F(100005), S(100005);
int main(){
	while (sdf(n), n){
		sdf(q);
		j = c = 0;
		for (int i = 0; i < n; i++) {
			sdf(a);
			A[i] = a;
			if (i && A[i-1] != a){
				for (int k = j; k < i; k++) {
					F[k] = c;
					S[k] = j;
				}
				c = 0;
				j = i;
			}
			c++;
		}
		for (int k = j; k < n; k++) {
			F[k] = c;
			S[k] = j;
		}

		segTree queries(F,0,n);
		while (q--){
			sdf(s); sdf(e);
			s--; e--;
			if ( (!s || A[s-1] != A[s]) && (e==n-1 || A[e+1] != A[e]) )
				a = F[queries.rmq(s,e)];
			else if ((s && A[s-1] == A[s]) &&  (e==n-1 || A[e+1] != A[e]) ) {
				int c1 = S[s]+F[s];
				a = max(c1-s, F[queries.rmq(c1,e)]);	
			}
			else if ((!s || A[s-1] != A[s]) && (e != n-1 && A[e+1] == A[e])){
				int c1 = e-S[e]+1;
				a = max(c1, F[queries.rmq(s,S[e]-1)]);	
			}
			else if ((s && A[s-1] == A[s]) && (e != n-1 && A[e+1] == A[e])){
				if (A[s] == A[e])
					a = e-s+1;
				else{
					int c1 = S[s]+F[s] - s, c2 = e-S[e]+1;
					a = max(c1,c2);
					if (S[s]+F[s] <= S[e]-1)
						a = max(a,F[queries.rmq(S[s]+F[s],S[e]-1)]);
				}
			}
			pdf(a);
			pendl();
		
		}


	
	}


	return 0;
}

