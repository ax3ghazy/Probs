#include <iostream>
#include <bitset>
using namespace std;


bitset<1000005> calender;
bool checkdoConflict(int a, int b){
    for (int i = a; i < b; i++){
        if (calender[i]) return true; 
        calender.set(i);    
    }
    return false;
}


int main() {
    int n, m;

    while( cin >> n >> m, n || m){
        calender.reset();
        bool conflict = false;
        int a, b, c;
        while(n--){
            cin >> a >> b;
            if (checkdoConflict(a,b)){
                conflict = true;
                for(int i=0; i < n; i++) cin >> a >> b;
                break;
            }
        }
        if (!conflict)
            while(m--){
                cin >> a >> b >> c;
                for ( ; b < 1000000; a +=  c, b += c )
                    if (checkdoConflict(a,b)){
                        conflict = true;
                        for(int i=0; i < n; i++) cin >> a >> b >> c;
                        break;
                    }
            }
        if(conflict) cout << "CONFLICT";
        else cout << "NO CONFLICT";
        cout << endl;
    }



    return 0;
}
