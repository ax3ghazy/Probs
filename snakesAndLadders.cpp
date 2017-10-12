#include <cstdio>
using namespace std;



int main(){
  int m,n, TC = 1, count;
  char field[105][105];
  while (scanf("%d %d", &n, &m), m || n){
    for (int i = 0; i < n; i++)
      scanf("%s",field[i]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++){
        if (field[i][j] == '*') continue;
        count = 0;
        for (int k = i-1; k < i+2; k++)
          for (int l = j-1; l < j+2; l++){
            if ((k == i && l == j) || k < 0 || l < 0 || k > n-1 || l > m-1)
              continue; 
            if (field[k][l] == '*') count++; 
          }
        field[i][j] = '0' + count;
      }
    printf("Field #%d:\n", TC);
    TC++;
    for (int i = 0; i < n; i++)
      printf("%s\n",field[i]);
    printf("\n");
  }


  

  return 0;
}
