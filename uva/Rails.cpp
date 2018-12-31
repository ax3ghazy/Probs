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
	int N, a, i, j, t = 0;
	while (sdf(N), N){
		while (sdf(a), a){
			bool poss = true;
			stack<int> station;
			i = j = 1;
			do {
				if (poss){
					if (!station.empty() && station.top() == a) 
						station.pop();
					else if (j<=a){
						while (j<a) station.push(j++);
						j++;	
					}
					else poss = false;
				}
				sdf(a);
			} while (++i < N);
			if(poss) printf("Yes");
			else printf("No");
			pendl();
		}
		pendl();
	}
	return 0;
}

