#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;




int main(){
  string game;
  char gm[25];
  while (getline(cin, game), game != "Game Over"){
    int n = game.length(), score = 0, j = 0;
    for (int i = 0; i < game.length(); i++)
      if(!isblank(game[i])) gm[j++] = game[i];
    n = j;
    for (int i = 0, j = 0; i < 10; i++){
      for (int k = 0; k < 2; k++){ // badcode
        if (isdigit(gm[j])){
          score += gm[j] - '0';
          j++;
        }
        else if (gm[j] == '/'){ // has to be on the second
          score += 10 - (gm[j-1] - '0');
          if (isdigit(gm[j+1]))
           score += gm[j+1] - '0'; 
          else
           score += 10;
          j++;
        }
        else {
          score += 10;
           
          if (isdigit(gm[j+1])){
           score += gm[j+1] - '0'; 
           if (j + 2 < n){
             if (isdigit(gm[j+2]))
              score += gm[j+2] - '0'; 
             else if (gm[j+2] == '/')
              score += 10 - (gm[j+1] - '0');
             else score += 10;
           }
          }
          else{
            score += 10;
            if (j+2 < n && isdigit(gm[j+2]))
             score += gm[j+2] - '0'; 
            else score+=10;
          }
          j++;
          break;
        }
      }

    }
    cout << score << endl;
  }
  return 0;
}
