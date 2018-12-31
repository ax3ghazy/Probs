#include <cstdio>
#include <iostream>
#include <string>
using namespace std;



int main(){
  char A[92];
  for (int i = '1'; i < '9'+1; i++) {
    switch(i) {
      case '1': A[i] = '1'; break;
      case '2': A[i] = 'S'; break;
      case '3': A[i] = 'E'; break;
      case '5': A[i] = 'Z'; break;
      case '8': A[i] = '8'; break;
      default: A[i] = '-';
    }
  }
  for (int i = 'A'; i < 'Z'+1; i++) {
    switch(i){
      case 'A': A[i] = 'A'; break;
      case 'E': A[i] = '3'; break;
      case 'H': A[i] = 'H'; break;
      case 'I': A[i] = 'I'; break;
      case 'J': A[i] = 'L'; break;
      case 'L': A[i] = 'J'; break;
      case 'M': A[i] = 'M'; break;
      case 'O': A[i] = 'O'; break;
      case 'S': A[i] = '2'; break;
      case 'T': A[i] = 'T'; break;
      case 'U': A[i] = 'U'; break;
      case 'V': A[i] = 'V'; break;
      case 'W': A[i] = 'W'; break;
      case 'X': A[i] = 'X'; break;
      case 'Y': A[i] = 'Y'; break;
      case 'Z': A[i] = '5'; break;
      default: A[i] = '-';
    }
  }
  string word;
  while (!(cin >> word).eof()){
    bool palin = true, mirror = true;
    int leng = word.length();
    for (int i = 0; i < leng/2+1 && (palin || mirror); i++){
      if (palin && word[i] != word[leng-1-i]) palin = false;
      if (mirror && (A[word[i]] != word[leng-1-i] || A[word[i]] == '-')) mirror = false;
    }
    cout << word << " -- ";
    if ( palin && mirror) cout << "is a mirrored palindrome.\n";
    else if (palin) cout << "is a regular palindrome.\n";
    else if (mirror) cout << "is a mirrored string.\n";
    else cout << "is not a palindrome.\n"; 
    cout << endl;

  }



  return 0;
}
