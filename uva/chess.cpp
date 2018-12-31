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
  int t, m, n;
  char c;
  scanf("%d", &t);
  while(t--){
    scanf("\n%c %d %d", &c, &m, &n);
    switch (c){
      case 'k':
        cout << (m*n+1)/2 << endl;
        break;
      case 'K':
        cout << ((m+1)/2) * ((n+1)/2) << endl;
        break;
      default:
        cout << min(m,n) << endl;
    }
  }




  return 0;
}
