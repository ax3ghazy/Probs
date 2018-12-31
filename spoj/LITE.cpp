#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <ctime>
#include <chrono> //C++11
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <functional>
#include <cstring>
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

int tree[50000000], lazy[50000000], A[50000000];

void updateRange(int node, int start, int end, int l, int r)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] = (end - start + 1) - tree[node];
        if(start != end)
        {
            lazy[node*2] = !lazy[node*2];                  // Mark child as lazy
            lazy[node*2+1] = !lazy[node*2+1];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end || start > r || end < l)              // Current segment is not within range [l, r]
        return;
    int mid = (start + end) / 2;
    if(start >= l && end <= r)
    {
        // Segment is fully within range
        tree[node] = (end - start + 1) - tree[node];
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] = !lazy[node*2];                  // Mark child as lazy
            lazy[node*2+1] = !lazy[node*2+1];                // Mark child as lazy
        }
        return;
    }
    updateRange(node*2, start, mid, l, r);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end || start > r || end < l)
        return 0;         // Out of range
    int mid = (start + end) / 2;
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] = (end - start + 1) - tree[node];            // Update it
        if(start != end)
        {
            lazy[node*2] = !lazy[node*2];                  // Mark child as lazy
            lazy[node*2+1] = !lazy[node*2+1];                // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l && end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	memset(lazy, 0, sizeof(int)*n);
	memset(A, 0, sizeof(int)*n);
	while (m--){
		int op, s, e; cin >> op >> s >> e;
		if (op == 0)
			updateRange(1, 1, n, s, e);
		else
			cout << queryRange(1, 1, n, s, e) << '\n';
	}

	return 0;
}
