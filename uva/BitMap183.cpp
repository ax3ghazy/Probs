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
int row, col, p;
char type, dig;
bool bm[200][200];

void B2D (int rs, int re, int cs, int ce){
	if (rs == re || cs == ce)
		return;

	int zCount = 0;
	for (int r = rs; r < re; r++)
		zCount += count(bm[r]+cs, bm[r]+ce, false);

	if (p && !(p%50))
		cout << '\n';
	p++;

	if (!zCount)
		cout << '1';
	else if (zCount == (re-rs)*(ce-cs))
		cout << '0';
	else{
		cout << 'D';
		int mr = (rs+re+1)/2, mc = (cs+ce+1)/2;
		B2D(rs, mr, cs, mc);
		B2D(rs, mr, mc, ce);
		B2D(mr, re, cs, mc);
		B2D(mr, re, mc, ce);
	}
}

void D2B (int rs, int re, int cs, int ce){
	if (rs == re || cs == ce)
		return;

	cin >> dig;
	if (dig == '0' || dig == '1'){
		for (int r = rs; r < re; r++)
			for (int c = cs; c < ce; c++)
				bm[r][c] = (dig&1);
	}
	else{
		int mr = (rs+re+1)/2, mc = (cs+ce+1)/2;
		D2B(rs, mr, cs, mc);
		D2B(rs, mr, mc, ce);
		D2B(mr, re, cs, mc);
		D2B(mr, re, mc, ce);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	while (cin >> type, type != '#'){
		cin >> row >> col;
		if (type == 'B'){
			cout << 'D' << right << setw(4) << row << right << setw(4) << col << '\n'; 
			for (int r = 0; r < row; r++) {
				for (int c = 0; c < col; c++) {
					cin >> dig;
					if (dig == '0')
						bm[r][c] = false;
					else
						bm[r][c] = true;
				}
			}
			p = 0;
			B2D(0, row, 0, col);
		}
		else{
			cout << 'B' << right << setw(4) << row << right << setw(4) << col << '\n'; 
			D2B(0, row, 0, col);
			int p = 0;
			for (int r = 0; r < row; r++) 
				for (int c = 0; c < col; c++) {
					if (p && !(p%50))
						cout << '\n';
					p++;
					cout << bm[r][c];
				}
				
		}
			cout << '\n';
	}

	return 0;
}
