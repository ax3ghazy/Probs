#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

int row[8], n;
bitset<50000> wperm;

bool works(int a, int b, int c){
  int ai=-1, bi=-1;
  for (int i = 0; i < n && ai!=-1 && bi!=-1; i++)
    if (row[i] == a) ai = i;
    else if (row[i] == b) bi = i;
  if (ai>bi) swap(ai,bi);
  return (c>0?(bi-ai > c): (bi-ai < -c));
}

int fac(int n){ //till 8
  return (n==1)? 1 : fac(n-1)*n;
}

int main() {
  int m,a,b,c; 
  for (int i = 0; i < 8; i++) row[i] = i;
  while(scanf("%d %d", &n, &m), n || m){
    wperm.reset();
    while(m--){
      scanf("%d %d %d", &a, &b, &c);
      int perm = 0;
      do {
        if(wperm[perm]){perm++; continue;}
        if (!works(a,b,c)) wperm[perm] = 1;
        perm++;
      } while(next_permutation(row, row+n));
    }
    printf("%d\n", fac(n)-int(wperm.count()));
  }

  return 0;
}
