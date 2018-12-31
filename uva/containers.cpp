#include <iostream>
#include <vector>
//#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    int t = 1;
    while (cin >> str, str != "end"){
        //        stack<char> first; first.push(str[0]);
        //        vector<stack<char>> port;  port.push_back(first);
        vector<char> port; port.push_back(str[0]);
        for (int i = 1; i < str.size(); i++) {
            int si = -1;  
            for (int j = 0; j < port.size(); j++) 
                if (port[j] == str[i]) {si = j; break;}
                else if (port[j] > str[i]){
                    if (si!=-1) {if (str[si] > str[j]) si = j;}
                    else si = j;
                }
            if (si == -1) port.push_back(str[i]);
            else port[si] = str[i];
        }
        cout << "Case " << t++ <<": "<< port.size() <<endl;
    }




    return 0;
}
