#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

int main(){
  int t;
  cin >> t;
  cin.ignore();
  cin.ignore();
  string line;
  while (t--){
    map <string, vector<string>> dic;
    list <pair<string, string>> out;

    while(getline(cin, line), line != ""){
      int n = line.length(), i = 0;
      string temp = line;
      sort(temp.begin(), temp.end());
      while(i < n && isblank(temp[i])) i++;
      temp = temp.substr(i);
      if (dic.count(temp)){
        for (int i = 0; i < dic[temp].size(); i++) {
          pair<string, string> ins;
          if (line < dic[temp][i]) ins = make_pair(line, dic[temp][i]);
          else ins = make_pair(dic[temp][i],line);
          auto it = out.begin();
          while (it != out.end() && it->first + it->second < ins.first + ins.second) it++;
          out.insert(it, ins);
        }
      }
      dic[temp].push_back(line);
    }
    for (auto it = out.begin(); it != out.end(); it++)
      cout << it->first << " = " << it->second << endl;
    if(t)  cout << endl;

  }




  return 0;
}
