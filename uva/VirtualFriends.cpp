#include <map>
#include <pair>
#include <string>
using namespace std;

typedef vector<int> vi;

class UnionFind {
    private: 
        vi p, rank, size;
    public:
        UnionFind(int n) {
            rank.assign(n,0); 
            size.assign(n,1);
            p.assign(n,0);
            for (int i = 0;i < n; i++) p[i] = i;
        }
        int findSet(int i) { return (p[i] == i)? i : (p[i] = findSet(p[i])); }
        int getSize(int i){ return size[findSet(i)]; }
        bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
        void unionSet (int i, int j){
            int x = findSet(i), y = findSet(j);
            if (!isSameSet(x,y)){
                if(rank[x] > rank[y]){ p[y] = x; size[x] += size[y]; }
                else{
                    p[x] = y;
                    size[y] += size[x];
                    if (rank[x]==rank[y]) rank[y]++;
                }
            }
        }
};

int main() {
    int n; cin >> n;
    while (n--){
        int m, enu = 1;
        string name[2];
        UnionFind network(2*m+5);
        map<string, int> record;
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> name[j];
                if (!record.count(name[j]) record[name[j]] = enu++;
            }
            network.unionSet(record[name[0]], record[name[1]]);
            cout << network.getSize(record[name[0]]) << endl;
         }
    }
    return 0;
}

//a better version:
//#include <cstdio>
//#include <map>
//#include <vector>
//#include <string>
//using namespace std;
//
//typedef vector<int> vi;
//
//class UnionFind {
//    private: 
//        vi p, rank, size;
//    public:
//        UnionFind(int n) {
//            rank.assign(n,0); 
//            size.assign(n,1);
//            p.assign(n,0);
//            for (int i = 0;i < n; i++) p[i] = i;
//        }
//        int findSet(int i) { return (p[i] == i)? i : (p[i] = findSet(p[i])); }
//        int getSize(int i){ return size[findSet(i)]; }
//        bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
//        void unionSet (int i, int j){
//            int x = findSet(i), y = findSet(j);
//            if (!isSameSet(x,y)){
//                if(rank[x] > rank[y]){ p[y] = x; size[x] += size[y]; }
//                else{
//                    p[x] = y;
//                    size[y] += size[x];
//                    if (rank[x]==rank[y]) rank[y]++;
//                }
//            }
//        }
//};
//
//int main() {
//    int n; scanf("%d", &n);
//    while (n--){
//        int m, enu = 0;
//        scanf("%d", &m);
//        char name1[25], name2[25];
//        string names1, names2;
//        UnionFind network(2*m+5);
//        map<string, int> record;
//        for (int i = 0; i < m; i++) {
//            scanf("%s %s", name1, name2);
//            names1 = string(name1);
//            names2 = string(name2);
//            if (!record.count(names1)) record[names1] = enu++;
//            if (!record.count(names2)) record[names2] = enu++;
//            network.unionSet(record[names1], record[names2]);
//            printf("%d\n", network.getSize(record[names1]));
//        }
//    }
//    return 0;
//}
