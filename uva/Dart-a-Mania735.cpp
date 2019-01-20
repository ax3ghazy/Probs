#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
#define EPS 1e-9
#define mp(A,B) make_pair(A,B)
#define sdf(n) scanf("%d",&n)
#define ssf(a) scanf(" %s ", a)
#define pdf(n) printf("%d",n)
#define pcf(c) printf("%c",c)
#define pdfn(n) printf("%d\n",n)
#define pb push_back
#define pendl() printf("\n")

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

#define endl '\n'
int perm;
vector<int> darts(3);
set<int> scores_set;
vector<int> scores;
set<vector<int>> solns;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 21; i++) {
        scores_set.insert(i);
        scores_set.insert(2*i);
        scores_set.insert(3*i);
    }
    scores_set.insert(50);
    for (int s : scores_set) {
        scores.pb(s);
    }

    int cur_score;
    while (cin >> cur_score, cur_score > 0) {

        perm = 0;
        darts[0] = darts[1] = darts[2] = 0;
        solns.clear();

        for (int i = 0; i < scores.size(); i++) {
            for (int j = 0; j < scores.size(); j++) {
                for (int k = 0; k < scores.size(); k++) {
                    darts[0] = scores[i], darts[1] = scores[j], darts[2] = scores[k];
                    if (darts[0]+darts[1]+darts[2] == cur_score) {
                        perm++;
                        //cerr << "soln: " << darts[0] << " " << darts[1] << " " << darts[2] << "(" << perm << ")" << endl;
                        sort(darts.begin(), darts.end());
                        solns.insert(darts);
                    }
                }
            }
        }

        if (solns.size()) {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << cur_score << " IS " << solns.size() << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << cur_score << " IS " << perm << "." << endl;
        } else {
            cout << "THE SCORE OF " << cur_score << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        cout << "**********************************************************************" << endl;
    }
    cout << "END OF OUTPUT" << endl;






    return 0;
}
