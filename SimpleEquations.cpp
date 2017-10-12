#include <cstdio>
#include <cmath>
using namespace std;


void solve(int& a, int& b, int& c){
  int isqrt=sqrt(c);
  for (int x = -isqrt; x <= isqrt; x++) 
    for (int y = -isqrt; y <= isqrt; y++)
      for (int z = -isqrt; z <= isqrt; z++)
        if (x!=y && y!=z && x!=z && x+y+z==a && x*y*z==b && x*x+y*y+z*z==c){
          printf("%d %d %d\n", x, y, z);
          return;
        }
  printf("No solution.\n");
}


int main() {
  int n;
  scanf("%d",&n);
  while(n--){
    int a, b, c;
    scanf("%d %d %d",&a, &b, &c);
    solve(a,b,c);
  }
  return 0;
}
