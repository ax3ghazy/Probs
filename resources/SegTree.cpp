

typedef vector<int> vi;


class segTree{ //min
	private:
		vi st, A;
		int n;
		int lefti(int i) {return (i<<1);}
		int righti(int i) {return (i<<1)+1;}
		
		void build (int i, int L, int R){
			if (L==R)
				st[i] = L;
			else{
				int avgSum = (L+R)/2;
				build(lefti(i), L, avgSum);
				build(righti(i), avgSum+1, R);
				int left = st[lefti(i)], right = st[righti(i)];
				st[i] = A[left] > A[right]? right : left;
			}
		}
		
		int rmq (int i, int L, int R, int s, int e){
			if (s > R || e < L) return -1;
			if (R <= e && L >= s) return st[i];
			
			int avgSum = (L+R)/2;
			int left = rmq (lefti(i), L, avgSum, s, e);
			int right = rmq (righti(i), avgSum+1, R, s, e);
			
			if (left == -1) return right;
			if (right == -1) return left;
			return (A[left] > A[right]? right : left);
		}
		
		int updatePoint (int i, int L, int R, int se, int val){
			if (se > R || se < L) return st[i];
			
			if (L == R && L == se){
				A[se] = val;
				return (st[i]=L); //in case we add new elements
			}
			
			int avgSum = (L+R)/2;
			int left = updatePoint (lefti(i), L, avgSum, se, val);
			int right = updatePoint(righti(i), avgSum+1, R, se, val);
			return (st[i] = A[left] > A[right]? right : left);
				
		}
	
	
	
	public:
		segTree (const vi& data){
			A = data;
			n = A.size();
			st.assign(4*n+1,-1);
			build(1, 0, n-1);
		}
		int rmq (int s, int e){
			return rmq(1, 0, n-1, s, e);
		}
		int updatePoint (int se, int val){
			updatePoint(1, 0, n-1, se, val);
		}
	
};