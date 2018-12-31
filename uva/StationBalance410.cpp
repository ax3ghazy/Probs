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

int c, s, i, j, dc, temp, temp2, t = 0;
double imb, avg, tempf;

int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed;
  while (cin >> c >> s){
    int A[10] = {0};
    dc = 0;
    imb = 0.0;
    for (i = 0; i < s; i++){
      cin >> temp;
      A[i] = temp;
      dc += temp;
    }
    avg = double(dc)/double(c);
    dc = c<<1;
    sort(A, A+dc);
    cout << "Set #" << ++t << '\n';
    for (i = 0, j = dc-1; i < c; ++i, --j){
      cout << ' ';
      cout << i << ":";

      temp = A[i], temp2 = A[j];
      tempf = 0.0;
      if (temp){
        cout << ' ' << temp;
	tempf += double(temp);
      }
      if (temp2){
        cout << ' ' << temp2;
	tempf += double(temp2);
      }
      imb += fabs(tempf-avg);
      cout << '\n';
    }
    cout << "IMBALANCE = " << setprecision(5) << imb << "\n\n";
  }






  return 0;
}
