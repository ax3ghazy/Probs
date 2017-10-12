#include <iostream>
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

int main(){
  long long t, a, b;
  scanf("%lld", &t);
  while (t--){
    scanf("%lld %lld", &a, &b);
    long long sum = a+b, diff = a-b;
    if ( diff < 0 || sum%2) cout << "impossible";
    else {
      b = sum/2;
      a -= b;
      printf("%lld %lld", b, a);
    }
    printf("\n");
  }


  return 0;
}
