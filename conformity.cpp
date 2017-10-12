#include <iostream>
#include <string>
using namespace std;

int main() {
    char c;
    string s="";
    int cursor = -1;
    while(!cin.get(c).eof()){
        if (c== '\n'){ cursor = -1; cout << s << endl; s=""; continue;}
         switch (c) {
             case '[': if (!s.empty()) cursor = 0; break;
             case ']': if (!s.empty()) cursor = -1; break;
             default:  if(cursor==-1) s+=c; else s.insert(cursor++,&c);
         }
    }



    return 0;
}
