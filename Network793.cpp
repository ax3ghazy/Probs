#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <bitset>
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
#define sdfn(n) scanf("%d\n",&n)
#define sds(a) scanf("%s", a)
#define pdf(n) printf("%d",n)
#define pdfn(n) printf("%d\n",n)
#define pb push_back
#define pendl() printf("\n")

//typedef later
#define ii pair<int,int>
#define iii pair<int,ii>
#define pque priority_queue
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

class  UFdsets {
    private: 
		int n;
        vi p, rank, size;
    public:
        UFdsets (int num) {
			n = num;
            rank.assign(n,0); 
            size.assign(n,1);
            p.assign(n,0);
            for (int i = 0;i < n; i++) p[i] = i;
        }
        int findSet(int i) { return (p[i] == i)? i : (p[i] = findSet(p[i])); }
        int getSize(int i){ return size[findSet(i)]; }
        bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
		int numSets(){ return n; }
        void unionSet (int i, int j){
            int x = findSet(i), y = findSet(j);
            if (!isSameSet(x,y)){
				n--;
                if(rank[x] > rank[y]){ p[y] = x; size[x] += size[y]; }
                else{
                    p[x] = y;
                    size[y] += size[x];
                    if (rank[x]==rank[y]) rank[y]++;
                }
            }
        }
};

int main(){
	int t, n, a, b, suc, fail;
	char c;
	sdf(t);
	while(t--){
		sdf(n); cin.ignore();
		UFdsets network(n+1);
		suc = fail = 0;
		while(scanf("%c", &c) == 1 && (c == 'c' || c == 'q')){
			sdf(a); sdf(b); cin.ignore();
			if (c == 'c')
				network.unionSet(a,b);
			else
				network.isSameSet(a,b)? suc++ : fail++;
		}
		printf("%d,%d\n",suc, fail);
		if (t) pendl();
	}
	return 0;
}