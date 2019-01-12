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
/*
ll bill(ll x) { // x > 0
    ll tot = 0;
    ll rates[] = {0, 2, 3, 5, 7};
    ll thres[] = {0, 100, 10000, 1000000, 0x7fffffff};
    ll i = 1;
    while (x > 0) {
        tot += rates[i]*min(x, thres[i]-thres[i-1]);
        x -= thres[i]-thres[i-1];
        i++;
    }
    return tot;
}
*/
ll bill(ll x) {
    if (0 < x && x <= 100) {
        return 2*x;
    } else if (100 < x && x <= 1e4) {
        return 2*100+3*(x-100);
    } else if (1e4 < x && x <= 1e6) {
        return 2*100+3*9900+5*(x-1e4);
    } else {
        return 2*100+3*9900+5*990000+7*(x-1e6);
    }
}

ll revbill(ll y) {
    if (2 <= y && y <= 200) {
        return y/2;
    } else if (203 <= y && y <= 29900) {
        return (y+100)/3;
    } else if (29905 <= y && y <= 4979900) {
        return (y+20100)/5;
    } else { //unique solution
        return (y+2020100)/7;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    //cerr << revbill(2716950) << endl;
    //cerr << bill(1185208)-bill(547410) << endl;
    while (cin >> A >> B, A || B) {
        ll sum = revbill(A);
        //cerr << "revbill(A) = " << sum << endl;
        //cerr << "bill(revbill(A)) = " << bill(sum) << endl;
        ll s = 1, e = sum/2;
        while (s <= e) {
            ll c0 = (s+e)/2;
            ll bc0 = bill(c0), bsummc0 = bill(sum-c0);
            ll det = bsummc0-bc0-B; 
            //cerr << det << endl;
            if (det > 0) {
                s = c0+1;
            }  else if (det < 0) {
                e = c0-1;
            } else {
                cout << bc0 << endl;
                break;
            }
        }
    }



    return 0;
}
