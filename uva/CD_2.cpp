#include <cstdio>
#include <algorithm>
using namespace std;

int n, t, maxi, cursum, cd[25], sol[25], curr[25], d;

void solve (int depth, int j = 0){
  if (cursum > maxi) {copy(curr, curr+depth, sol); maxi = cursum; d = depth;}
  if (maxi==n || depth == t) return;
  for (int i = j; i < t; i++) 
    if (cursum+cd[i] <= n) {
      curr[depth] = cd[i];
      cursum+=cd[i];
      solve(depth+1, i+1);
      cursum-=cd[i];
      curr[depth] = -1;
    }
}

int main() {
  while (scanf("%d", &n) != EOF){
    maxi = 0; cursum = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) scanf("%d", cd+i);
    solve(0);
    for (int i = 0; i < d; i++) printf("%d ", sol[i]);
    printf("sum:%d\n", maxi);
  }
  return 0;
}
