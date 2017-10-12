typedef vector<int> vi;
class UnionFind {
    private: 
        vi p, rank, size;
		int n;
    public:
        UnionFind(int num) {
			n = num;
            rank.assign(n,0); 
            size.assign(n,1);
            p.assign(n,0);
            for (int i = 0;i < n; i++) p[i] = i;
        }
        int findSet(int i) { return (p[i] == i)? i : (p[i] = findSet(p[i])); }
        int getSize(int i){ return size[findSet(i)]; }
        bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
		int numSets(){ return n; }
        void unionSet (int i, int j){
            int x = findSet(i), y = findSet(j);
            if (!isSameSet(x,y)){
				n--;
                if(rank[x] > rank[y]){ p[y] = x; size[x] += size[y]; }
                else{
                    p[x] = y;
                    size[y] += size[x];
                    if (rank[x]==rank[y]) rank[y]++;
                }
            }
        }
};
