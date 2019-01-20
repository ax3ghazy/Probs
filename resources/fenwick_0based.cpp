#include <vector>
using namespace std;

class FenwickTree {
    private:
        vector<int> T; //T[i] == sum A[g(i)...i] ;
        int n;

        //g(i) = i & (i+1)
        inline int boundary_g(int i) {
            return i&(i+1);
        }

        //h(j) = next j such that g(j) <= i <= j
        inline int nextj_h(int j) {
            return j|(j+1);
        }

    public:
        FenwickTree(int n) {
            T.assign(n, 0);
            this->n = n;
        }

        FenwickTree(vector<int> A) {
            n = A.size();
            T.assign(n, 0);
            for (int i = 0; i < n; i++) {
                add(i, A[i]);
            }
        }

        void add(int i, int delta) {
            int j = i;
            for (; j < n; j = nextj_h(j)) {
                T[j] += delta;
            }
        }

        int sum(int r) {
            int res = 0;
            for (; r >= 0; r = boundary_g(r)-1) { //nested loops for multidimensions!
                res += T[r];
            }
            return res;
        }

        int sum(int l, int r) {
            return sum(r)-sum(l-1);
        }

};
