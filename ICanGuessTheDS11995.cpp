#include <bits/stdc++.h>
using namespace std;

#define infint 0x7fffffff //32-bit int
#define ninfint 0x80000000
#define EPS 1e-9

#define pb push_back

#define isOn(S, j) ((S) & (1 << (j)))
#define setBit(S, j) (S |= (1 << (j)))
#define clearBit(S, j) (S &= ~(1 << (j)))
#define toggleBit(S, j) (S ^= (1 << (j)))
#define lowBit(S) ((S) & (-(S)))
#define setAll(S, n) (S = (1 << (n)) - 1)
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
	int n;
	while (cin >> n, !cin.eof()){
		stack<int> st;
		queue<int> q;
		pque<int> pq;

		bool st_poss = true, q_poss = true, pq_poss = true;

		while(n--){
			int cmd, x;
			cin >> cmd >> x;
			if (cmd == 1)
				st.push(x), q.push(x), pq.push(x);
			else {
				//stack
				if (st.empty() || st.top() != x)
					st_poss = false;
				else if (st_poss)
					st.pop();
				//queue
				if (q.empty() || q.front() != x)
					q_poss = false;
				else if (q_poss)
					q.pop();
				//pque
				if (pq.empty() || pq.top() != x)
					pq_poss = false;
				else if (pq_poss)
					pq.pop();
			}
		}
		int sum_poss = q_poss + st_poss + pq_poss;
		if (sum_poss == 0)
			cout << "impossible\n";
		else if (sum_poss > 1)
			cout << "not sure\n";
		else {
			if (q_poss)
				cout << "queue\n";
			else if (pq_poss)
				cout << "priority queue\n";
			else
				cout << "stack\n";
		}
	}

	return 0;
}
