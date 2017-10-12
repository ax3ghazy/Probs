#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x;
    vector<int> set; 
    while(!(cin >> x).eof()) {
       set.push_back(x);
       sort(set.begin(), set.end());
       if (set.size()%2) cout << set[set.size()/2];
       else cout << (set[set.size()/2]+set[set.size()/2-1])/2;
       cout << endl;
        
    }
    return 0;
}
