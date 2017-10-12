#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int s, d, maxi, tot5, tot, last5[5];

void solve (int month) {
  if (month == 12) { if(tot > maxi) maxi = tot; return; }
  if (month>4) tot5-=last5[month%5];
  if (month < 4 || tot5+s < 0) {
    tot += s;
    tot5+=s;
    last5[month%5]=s;
    solve(month+1);
    tot -= s;
    tot5-= s;
  }
  if (month < 4 || tot5+d < 0) {
    tot += d;
    tot5+=d;
    last5[month%5]=d;
    solve(month+1);
    tot -= d;
    tot5 -= d;
  }
}


int main(){
  while (scanf("%d %d", &s, &d) != EOF){
    tot = tot5 = maxi = 0;
    d = -d;
    solve(0);
    if(maxi)
      printf("%d\n", maxi);  
    else
      printf("Deficit\n");  
  }
  return 0;
}
