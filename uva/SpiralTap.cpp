#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

#define mp(A,B) make_pair(A,B)



int main(){
  long long int n, pTarg;
  while (scanf("%lld %lld", &n, &pTarg), n || pTarg){
    long long int x, y, p = 1, dr = 1, dc = 0, rnd = 1;
    x = n/2 + 1;
    y = x;
    while ( p <= n*n && p != pTarg){
      for (int i = 0; i < 2; i++) {
        if (pTarg <= p + rnd){
          long long int diff = pTarg - p;
          y += dr * diff;
          x += dc * diff;
          p = pTarg;
          break;
        }
        else{
          y += dr * rnd;
          x += dc * rnd;
          p += rnd;
        }
        dr = -dr;
        swap(dr,dc);
      }
      rnd++;
    }
    printf("Line = %lld, column = %lld.\n", y, x); 
  }
  return  0;
}
