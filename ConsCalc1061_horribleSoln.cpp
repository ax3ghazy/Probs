#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

#define mp(A,B) make_pair(A,B)



int main(){
  pair<string, string> combs[6] = {mp("AA","A"), mp("AB","AB"), mp("AO","A"), mp("BB","B"), mp("BO","B"),mp("OO","O")};
  pair<string, string> signCombs[3] = {mp("++","+"), mp("+-","+"), mp("--","-")};
  string in1, in2, out;
  int t = 1;
  while(cin >> in1 >> in2 >> out, in1 != "E"){
    cout << "Case " << t++ << ": ";
    set<string> possString;
    set<string> possSign;
    int swp = false;

    string in1Lett = "", in2Lett = "", in1Signs, in2Signs;
    for (int i = 0; i < in1.size() && in1 != "?"; i++) 
      if (isalpha(in1[i])) in1Lett += in1[i];
      else in1Signs = in1[i];

    for (int i = 0; i < in2.size() && in2 != "?"; i++) 
      if (isalpha(in2[i])) in2Lett += in2[i];
      else in2Signs = in2[i];

    if (in1Lett == "A") in1Lett = "AO"; 
    else if (in1Lett == "B") in1Lett = "BO";
    else if (in1Lett == "O") in1Lett = "O";

    if (in2Lett == "A") in2Lett = "AO"; 
    else if (in2Lett == "B") in2Lett = "BO";
    else if (in2Lett == "O") in2Lett = "O";

    if (in1Signs ==  "+") in1Signs = "+-";
    else in1Signs = "-";
    if (in2Signs ==  "+") in2Signs = "+-";
    else in2Signs = "-";

    string outLett, outSigns;
    for (int i = 0; i < out.size() && out != "?"; i++) 
      if (isalpha(out[i])) outLett += out[i];
      else outSigns = out[i];

    if (out == "?"){
      for (int i = 0; i < in1Lett.length(); i++) {
        for (int j = 0; j < in2Lett.length(); j++) {
          string str = "XX";
          if (in1Lett[i] < in2Lett[j]){ str[0] = in1Lett[i]; str[1] = in2Lett[j];}
          else { str[0] = in2Lett[j]; str[1] = in1Lett[i];}
          for (int m = 0; m < 6; m++)
            if ( combs[m].first == str ) str = combs[m].second;
          possString.insert(str);
        }
      }
      for (int i = 0; i < in1Signs.length(); i++) {
        for (int j = 0; j < in2Signs.length(); j++) {
          string str = "XX";
          if (in1Signs[i] < in2Signs[j]) {str[0]  = in1Signs[i]; str[1] = in2Signs[j];}
          else { str[0] = in2Signs[j]; str[1] = in1Signs[i];}
          for (int m = 0; m < 3; m++)
            if ( signCombs[m].first == str ) str = signCombs[m].second;
          possSign.insert(str);
        }
      }

      cout << in1 << " " << in2 << " ";
      out = "";
      int i = 0;
      for (const auto& abo : possString)
        for (const auto& rh : possSign) {
          if (i++) out += ", ";
          out += abo;
          out += rh;
        }
      if (i == 1)
        cout << out << endl;
      else 
        cout << "{" << out << "}\n";
    }
    else {
      if (in1 == "?") {
        swap(in1, in2);
        swap(in1Lett, in2Lett);
        swap(in1Signs, in2Signs);
        swp = true;
      }

      if (outLett == "A") outLett = "AAAO";
      else if (outLett == "B") outLett = "BBBO";
      else if (outLett == "AB") outLett = "AB";
      else outLett = "OO";
      if (outSigns ==  "+") outSigns = "+-++";
      else outSigns = "--";

      for (int i = 0; i < in1Lett.size(); i++) {
        for (int j = 0; j < outLett.size(); j += 2) {
          int oth;
          if (in1Lett[i] == outLett[j]){ oth = j+1;}
          else if (in1Lett[i] == outLett[j+1]) { oth = j;}
          else continue;
          for (int m = 0; m < 6; m++) {
            if (outLett[oth] == combs[m].first[0] ||  outLett[oth] == combs[m].first[1])
              possString.insert(combs[m].second);
          }
        }
      }
      for (int i = 0; i < in1Signs.size(); i++) {
        for (int j = 0; j < outSigns.size(); j += 2) {
          int oth;
          if (in1Signs[i] == outSigns[j]){oth = j+1;}
          else if (in1Signs[i] == outSigns[j+1]) {oth = j;}
          else continue;
          for (int m = 0; m < 3; m++) {
            if (outSigns[oth] == signCombs[m].first[0] ||  outSigns[oth] == signCombs[m].first[1])
              possSign.insert(signCombs[m].second);
          }
        }
      }
      if (!(swp)){
        cout << in1 << " ";
        if (possString.empty() || possSign.empty()) cout << "IMPOSSIBLE ";
        else {
          cout << "{";
          int i = 0;
          for (const auto& abo : possString)
            for (const auto& rh : possSign) {
              if (i++) cout << ", ";
              cout << abo << rh;
            }
          cout << "} ";
        }
      }
      else{
        if (possString.empty() || possSign.empty()) cout << "IMPOSSIBLE ";
        else {
          cout << "{";
          int i = 0;
          for (const auto& abo : possString)
            for (const auto& rh : possSign) {
              if (i++) cout << ", ";
              cout << abo << rh;
            }
          cout << "} ";
        }
        cout << in1 << " ";
      }
      cout << out << endl;
    }

  }




  return 0;
}
