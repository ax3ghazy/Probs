#include <iostream>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

int main () {
	int s, b;
	pii soldier[100003];
	while (cin >> s >> b, s||b){
		for (int i = 1; i <= s; i++)
			soldier[i] = make_pair(i-1,i+1);
		soldier[1].first = -1; soldier[s].second = -1;
		int l , r;
		for (int i = 0; i < b; i++){
			cin >> l >> r;	
			if (soldier[l].first!=-1){
				soldier[soldier[l].first].second = soldier[r].second;
				cout << soldier[l].first;
			}
			else cout << "*";
			cout << " ";
			if (soldier[r].second!=-1){
				soldier[soldier[r].second].first = soldier[l].first;
				cout << soldier[r].second;
			}
			else cout << "*";
			cout << endl;
				
		} 
		cout << "-\n";
	}
    return 0;
}
