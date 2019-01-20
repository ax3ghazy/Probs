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

int r, c, kings = 0;
int board[100][100];
bool solved = false;

bool can_place(int i, int j) {
    int empty_sur = 0;
    bool blocking = false;
    for (int ii = i-1; ii <= i+1; ii++) {
        for (int jj = j-1; jj <= j+1; jj++) {
            if ((ii == i && jj == j) || ii < 0 || ii > r-1 || jj < 0 || jj > c-1) {
                continue;
            }
            if (board[ii][jj] == 1) {
                blocking = true;
            } else if (board[ii][jj] == -1) {
                empty_sur++;
            }
        }
    }

    return !blocking && empty_sur >= 1;
}

void place(int i, int j, bool place) {
    int empty_sur = 0;
    for (int ii = i-1; ii <= i+1; ii++) {
        for (int jj = j-1; jj <= j+1; jj++) {
            if ((ii == i && jj == j) || ii < 0 || ii > r-1 || jj < 0 || jj > c-1) {
                continue;
            }
            if (board[ii][jj] != -1) {
                if (place){
                    board[ii][jj]--;
                } else {
                    board[ii][jj]++;
                }
            } else {
                empty_sur++;
            }
        }
    }
    if (place) {
        board[i][j] = empty_sur;
    } else {
        board[i][j] = -1;
    }
}

void solve(int k, int i, int j) {
    if (i > r-1 || j > c-1) {
        return;
    }

    for (int ii = i; ii < r && !solved; ii++) {
        for (int jj = j; jj < c && !solved; jj++) {
            if (can_place(ii, jj)) {
                place(ii, jj, true);
                kings = max(kings, k+1);

                solve(k+1, ii+(jj+1)/c, (jj+1)%c);

                place(ii, jj, false);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&board[0][0], &board[0][0]+sizeof(board)/sizeof(board[0][0]), -1);
    cin >> r >> c;
    //solve(0, 0, 0);
    //cout << kings << endl;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (can_place(i, j)) {
                place(i, j, true);
                kings++;
            }
        }
    }


    cout << kings << endl;

    return 0;
}
