#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
 
struct teamdata_t{
    int id;
    int penalty = 0;
    map <int, int> solved;
    map<int, int> incorrect;
    teamdata_t() {penalty = 0;}
    teamdata_t(int ID) {id = ID;}
};
 
vector<teamdata_t> scoreboard;
 
bool compare(teamdata_t a, teamdata_t b){
    if (a.solved.size()> b.solved.size()) return true;
    else if (a.solved.size() <b.solved.size()) return false;
 
    if (a.penalty < b.penalty) return true;
    else if (a.penalty >b.penalty) return false;
 
    return (a.id<b.id);
}
int findt (int id){
    for (int i = 0; i < scoreboard.size(); i++)
        if (scoreboard[i].id == id) return i;
    return -1;
}
 
int main () {
    int n; cin >> n; cin.ignore(2);
    while (n--){
        int id, p, t; char s;
        string parser;
        scoreboard.clear();
        while (!getline(cin, parser).eof()){
        	if (parser.empty()) break;
        	stringstream ss(parser);
        	ss >> id >> p >> t >> s;
            int found = findt(id);
            if (found==-1){ scoreboard.push_back(teamdata_t(id)); found = scoreboard.size()-1;}
            if ( s =='C' && !scoreboard[found].solved[p]++ ) {
                int added = t;
                if(scoreboard[found].incorrect.count(p)) added += 20*scoreboard[found].incorrect[p];
               	scoreboard[found].penalty += added;
            }
            else if  (s=='I') scoreboard[found].incorrect[p]++;
        }
        sort(scoreboard.begin(), scoreboard.end(), compare);
        for (int i = 0; i < scoreboard.size(); i++)
            printf("%d %d %d\n", scoreboard[i].id, scoreboard[i].solved.size(), scoreboard[i].penalty);
		cout << endl;
    }
 
 
 
 
    return 0;
}
