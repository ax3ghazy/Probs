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
#include <cstring>
using namespace std;

#define mp(A,B) make_pair(A,B)
#define mxstr 100000000
#define sdf(n) scanf("%d",&n)
#define sds(a) scanf("%s", a)
#define ii pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define pendl() printf("\n")


int main(){
	int c, cap, tpd, m, tarr, t;
	char side[10];
	bool atLeft;
	sdf(c);
	while(c--){
		sdf(cap); sdf(tpd); sdf(m);
		vector<iii> all;
		all.reserve(m);
		queue<iii> left, right;
		for (int i = 0; i < m; i++) {
			sdf(tarr); sds(side);
			if (side[0] == 'l') 
				left.push(iii(i,ii(tarr,-1)));
			else
				right.push(iii(i,ii(tarr,-1)));
		}
		t = 0;
		atLeft = true;

		while(!left.empty() || !right.empty()){
			if (atLeft){
				if (!left.empty() && left.front().second.first <= t){
					for (int i = 0;!left.empty() && i < cap && left.front().second.first <= t; i++) {
						left.front().second.second = t + tpd;
						all.pb(left.front());
						left.pop();
					} 
					t += tpd;
					atLeft = false;
				}
				else if (!right.empty() && right.front().second.first <= t){
					t += tpd;
					atLeft = false;
				}
				else {
					if (!left.empty() && !right.empty())
						t = min(right.front().second.first, left.front().second.first);
					else if (!left.empty())
						t = left.front().second.first;
					else
						t = right.front().second.first;
				}
			}
			else {
			   	if (!right.empty() && right.front().second.first <= t){
					for (int i = 0; !right.empty() && i < cap && right.front().second.first <= t; i++) {
						right.front().second.second = t + tpd;
						all.pb(right.front());
						right.pop();
					} 
					t += tpd;
					atLeft = true;
				}
				else if (!left.empty() && left.front().second.first <= t){
					t += tpd;
					atLeft = true;
				}
				else{
					if (!left.empty() && !right.empty())
						t = min(right.front().second.first, left.front().second.first);
					else if (!left.empty())
						t = left.front().second.first;
					else
						t = right.front().second.first;
				}
			}
		}
		sort(all.begin(), all.end());
		for (const iii& pr : all)
			printf("%d\n", pr.second.second);
		if(c) pendl();
	}
	return 0;
}

