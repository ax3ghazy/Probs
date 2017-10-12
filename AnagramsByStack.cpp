#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

#define mp(A,B) make_pair(A,B)
#define mxstr 100000000


string src, trg, soln;
int n, m;
set<string> solns;


void backtrack(stack<char>& s, int srci = 1, int trgi = 0, int i = 1){
  if (i == 2*n){
    if (soln[i-1] == 'o') solns.insert(soln);
    return;
  }

  if (trgi < n && !s.empty() && s.top() == trg[trgi]){
    s.pop();
    soln[i] = 'o';

    backtrack(s, srci, trgi+1, i+1);

    s.push(trg[trgi]);
  }
  if (srci < n){
    s.push(src[srci]);
    soln[i] = 'i';

    backtrack(s, srci+1, trgi, i+1);

    s.pop();
  }
}


int main(){
  while(!(cin >> src >> trg).eof()){
    n =  src.size();
    if (n == trg.size()) { // clear
      soln.resize(2*n);
      soln[0] = 'i';
      stack<char> s;
      s.push(src[0]);
      backtrack(s);
    }
    //sort
    cout << "[\n";
    for (const auto& str : solns){
      for (int j = 0; j < str.size(); j++){
        if (j>0) cout << ' ';
        cout << str[j];
      }
      cout << endl;
    }
    cout << "]\n";
    solns.clear();
  }


  return 0;
}

