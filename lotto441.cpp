#include <cstdio>
using namespace std;


int main() {
  int k, s[12], t=0;
  while(scanf("%d",&k), k){
    if(t++) printf("\n");
    for (int i = 0; i < k; i++) scanf("%d",s+i);
    for (int q = 0; q < k-5; q++)
      for (int w = q+1; w < k-4; w++)
        for (int e = w+1; e < k-3; e++)
          for (int r = e+1; r < k-2; r++)
            for (int t = r+1; t < k-1; t++)
              for (int y = t+1; y < k; y++)
                printf("%d %d %d %d %d %d\n",s[q], s[w], s[e], s[r], s[t], s[y]);
  }
  return 0;
}
