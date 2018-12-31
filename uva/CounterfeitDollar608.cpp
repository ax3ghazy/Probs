#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
#define EPS 1e-9

#define pb push_back

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define pque priority_queue 


typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	string LStrings[3], RStrings[3], result[3];
	bool status[12];
	string guess[12];
	while (t--){
		for (int i = 0; i < 3; i++){
			cin >> LStrings[i] >> RStrings[i] >> result[i];
			if (result[i][0] == 'e'){ //even
				int n = LStrings[i].size();
				for (int j = 0; j < n; j++){
					status[LStrings[i][j]-'A'] = true;
					status[RStrings[i][j]-'A'] = true;
				}
			} else{
				for (int j = 0; j < 12; j++){
					bool onL = LStrings[i].find(j+'A') != string::npos, onR = RStrings[i].find(j+'A') != string::npos;
					if ((!onL && !onR) || status[j]) //just to skip
						status[j] = true;
					else { //one on L or R
						string oldguess = guess[j];
						guess[j] = "heavy";
						if ((onR && result[i][0] == 'u') || (onL && result[i][0] == 'd'))
							guess[j] = "light";

						if (guess[j] != oldguess && !oldguess.empty())
							status[j] = true;
					}
				}
			}
		}
		for (int i = 0; i < 12; i++) {
			if (status[i] == false)//should happen only once
				cout << (char)(i+'A') << " is the counterfeit coin and it is " << guess[i] << ".\n";
			guess[i] = "";
			status[i] = false;
		}
	}

	return 0;
}
