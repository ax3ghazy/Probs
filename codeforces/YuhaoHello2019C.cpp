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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    multiset<int> left, right;
    int balanced = 0;

    for (int i = 0; i < n; i++) {
        stack<char> paran;
        string sequence;
        cin >> sequence;
        stack<bool> matcher;

        for (int j = 0; j < sequence.length(); j++) {
            if (sequence[j] == '(') {
                matcher.push(0);
            } else {
                if (!matcher.empty() && matcher.top() == 0) {
                    matcher.pop();
                } else {
                    matcher.push(1);
                }
            }
        }

        int leftcnt = 0, rightcnt = 0;
        while (!matcher.empty()) {
            if (matcher.top() == 0)
                leftcnt++;
            else
                rightcnt++;
            matcher.pop();
        }
        //cerr << leftcnt << " " << rightcnt << endl << flush;

        if (leftcnt && rightcnt) {
            continue;
        } else if (leftcnt) {
            left.insert(leftcnt);
        } else if (rightcnt) {
            right.insert(rightcnt);
        } else {
            balanced++;
        }
    }

    int pairs = 0;
    for (auto it = left.begin(); it != left.end(); ++it) {
        auto it2 = right.find(*it);
        if (it2 != right.end()){
            pairs++;
            right.erase(it2);
        }
    }
    cout << pairs+balanced/2;

    

    return 0;
}
