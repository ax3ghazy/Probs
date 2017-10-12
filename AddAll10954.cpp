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
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
#define pque priority_queue


int main(){
	int n, a, sum, prev;
	while (sdf(n), n){
		pque<int, vector<int>, greater<int>> nums;
		sum = 0;
		while (n--){
			sdf(a);
			nums.push(a);
		}
		while (nums.size() > 1){
			prev = nums.top();
			nums.pop();
			prev += nums.top();
			nums.pop();
			sum += prev;
			nums.push(prev);
		}
		pdfn(sum);
	}
	return 0;
}

