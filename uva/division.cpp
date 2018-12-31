#include <cstdio>
using namespace std;


int main() {
  int n, num = 0; 
  while (scanf("%d",&n),n){
    if (num++) printf("\n"); 
    int abcde, fghij,soln=0;
    for (fghij = 1234; fghij <= 98765/n; fghij++){
      abcde = fghij * n;
      int temp = fghij, bitmask = (fghij < 10000);
      do { bitmask |= (1 << temp%10); } while (temp /= 10);
      temp = abcde;
      do { bitmask |= (1 << temp%10); } while (temp /= 10);
      if (bitmask == (1<<10)-1){soln++; printf("%05d / %05d = %d\n", abcde, fghij, n);}
    }
    if(!soln) printf("There are no solutions for %0d.\n", n);
  }
  return 0;
}
