#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n; cin.ignore(2);
    while (n--){
        map<string, int> record;
        string tree; int treenum = 0;
        while (getline(cin, tree), !tree.empty()){
            record[tree]++;
            treenum++;
            tree = "";
        }
        for (auto&& it : record)
            cout << it.first << ' ' << fixed << setprecision(4) << it.second/double(treenum)*100.0 << endl;
        if (n) cout << endl;     




    }    

    return 0;
}
