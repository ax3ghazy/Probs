#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int row[8] = {}, a, b, soln = 1;

bool isPossible(int r, int c){
  for (int i = 0; i < c; i++)
    if(row[i] == r || abs(i-c) == abs(row[i]-r)) return false;
  return true;
}

void solve(int c){
  if(c == 8 && row[b] == a){
    printf("%2d      ", soln++);
    for (int i = 0; i < 8; i++){
      printf("%d", row[i]+1);
      if (i<7) printf(" ");
    }
    printf("\n"); 
    return;
  }
  for (int r = 0; r < 8; r++) {
    if (isPossible(r,c)) {
      row[c] = r;
      solve(c+1);
    }
  }
}


int main() {
  int n; scanf("%d",&n);
  while (n--){
    scanf("%d %d", &a, &b); a--; b--;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    solve(0);
    if (n) printf("\n");
    soln = 1;
  }
  return 0;
}
