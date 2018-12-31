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
#define ii pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define pendl() printf("\n")
#define pque priority_queue

struct comp {
	bool operator() ( const iii& lhs, const iii& rhs){
		return lhs.first == rhs.first? lhs.second.first > rhs.second.first : lhs.first > rhs.first;
	}
};


int main(){
	char s[10];
	int srv,per, n, t;
	pque<iii, vector<iii>, comp> heap;
	while (scanf("%s",s), s[0] == 'R'){
		sdf(srv); sdf(per);
		heap.push(iii(per,ii(srv,per)));
	}
	sdf(n);
	while(n){
		t = heap.top().first;
		while(heap.top().first == t && n){
			n--;
			srv = heap.top().second.first;
			per = heap.top().second.second;
			pdfn(srv);
			heap.pop();
			heap.push(iii(t+per,ii(srv,per)));
		}
	}


	return 0;
}

