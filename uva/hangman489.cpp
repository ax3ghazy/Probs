#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int r;
  char word[1000], seq[1000];
  while(scanf("%d", &r), r != -1){
    scanf ("%s\n%s", word, seq);
    printf("Round %d\n", r);
    int wrong = 0, correct = 0, n = strlen(word), m = strlen(seq);
    for (int i = 0; i < m; i++) {
      bool sth = false;
      for (int j = 0; j < n; j++)
        if (seq[i] == word[j]) { word[j] = '-'; correct++; sth = true;} 

      for (int l = 0; l < i && !sth; l++) 
        if (seq[i] == seq[l]) sth = true;

      if (!sth) 
        wrong++;
      if (correct == n) {printf("You win."); break;}
      if (wrong == 7) {printf("You lose."); break;}
    }
      if (correct!=n && wrong !=7) printf("You chickened out."); 
      printf("\n");
  }



  return 0;
}
