#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int t, comps[3000000]; scanf("%d", &t);
  while(t--){
    int a, n, q, p; scanf("%d\n%d", &q, &n);
    bool solved = false;
    if (!q) solved = true;
    comps[0] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &p); 
      if(!solved){
        int size = (1 << i);
        for (int j = 0; j < size; j++) {
          comps[size+j] = p+comps[j];
          if(comps[size+j] == q){ solved = true; break;}
        }
      }
    }
    if (solved) printf ("YES");
    else printf("NO");
    printf("\n");
  }
  return 0;
}
