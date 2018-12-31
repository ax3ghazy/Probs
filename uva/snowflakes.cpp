#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    while(n--){
        int m,s = 0, max = 0; cin >> m;
        map <int, vector<int>> snowflakes; 
        for (int i = 0; i < m; i++) {
            int si; cin >> si;
            if (!snowflakes.count(si) || snowflakes[si].back() < s) snowflakes[si].push_back(i);
            else {
                if (i-s > max) max = i-s;
                s = snowflakes[si].back()+1;
                snowflakes[si].push_back(i);
                continue;
            }
            if ( i==m-1 && i-s+1 > max) max = i-s+1;
        }
        cout << max << endl;
    }
    return 0;
}
