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

char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
vector<string> hand;
string ace = "";
bool sequential = true, samesuit = true;

int subtract_rank(string card1, string card2) {
    char rank1 = card1[0], rank2 = card2[0];
    return find(ranks, ranks+sizeof(ranks), rank1) - find(ranks, ranks+sizeof(ranks), rank2);
}
bool less_rank(string card1, string card2) {
    return subtract_rank(card1, card2) <= 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 5; i++) {
        string card;
        cin >> card;
        if (card[0] != 'A') {
            hand.pb(card);
        } else {
            ace = card;
        }
    }

    if (hand.size() >= 4) {
        sort(hand.begin(), hand.end(), less_rank);
        for (int i = 0; i < hand.size()-1; i++) {
            if (subtract_rank(hand[i+1], hand[i]) != 1) {
                sequential = false;
            }
            if (hand[i+1][1] != hand[i][1]) {
                samesuit = false;
            }
        }
    }

    if (hand.size() < 4 || !samesuit || !sequential) {
        cout << "NO";
    } else if (ace.empty()) {
        cout << "YES";
    } else if (ace[1] == hand[0][1] && ((*hand.begin())[0] == '2' || (*hand.rbegin())[0] == 'K')) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cout << endl;





    return 0;
}
