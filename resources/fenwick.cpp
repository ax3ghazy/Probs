#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define rmOne(S) (S & (-S))

typedef vector<int> vi;

class fenwickTree {
	private:
		vi ft;
		inline void next (int& i){i += rmOne(i);}
		inline void parent(int& i) { i &= ~rmOne(i);}

	public:
		fenwickTree (int n){
			ft.assign(n+1, 0);
		}

        void adjust(int k, int v) {
            for (; k < (int)ft.size(); k += rmOne(k))
                ft[k] += v;
        }

		void update (int i, int diff){
			i++;
			while (i<ft.size()){
				ft[i] += diff;
				next(i);
			}
		}
		
		int rsq (int b){
			b++;
			int sum = 0;
			while (b){
				sum += ft[b];
				parent(b);
			}
			return sum;
		}

		int rsq (int a, int b){
			return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
		}

};


int main() {              
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	
	int n = sizeof(A)/sizeof(int);
	fenwickTree ft(n);
	for (int i = 0; i < n; i++)
		cout << A[i]+ft.rsq(i) << ' ';
    cout << endl;
	ft.update(5, -1);
	for (int i = 0; i < n; i++)
		cout << A[i]+ft.rsq(i) << ' ';
    cout << endl;
	ft.update(6, -1);
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << A[i]+ft.rsq(i) << ' ';
    cout << endl;
	

	return 0;
} 





