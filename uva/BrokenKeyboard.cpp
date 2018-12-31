#include <iostream>
#include <list>
#include <string>
using namespace std;
 
int main(){
    string c;
    while(getline(cin,c)){
		list<char> s;
    	list<char>::iterator it=s.begin();
        for (int i = 0; i < c.size(); i++)
            switch (c[i]){
                case '[': it=s.begin(); break;
                case ']': it=s.end(); break ;
                default: s.insert(it,c[i]);
            }
        for (auto&& i : s)
			cout << i;
		cout << endl;
    }
    return 0;
}








///////////////////////////
//#include <cstdio>
//#include <string>
//using namespace std;
//
//int main(){
//    char c;
//    string s; s.clear(); s.reserve(100005);
//    string::iterator it=s.end();
//    while(scanf("%c",&c)!=EOF)
//        switch (c){
//            case '\n': printf("%s\n",s.c_str()); s.clear(); s.reserve(100005); it=s.end(); break;
//            case '[': it=s.begin(); break;
//            case ']': it=s.end(); break ;
//            default: s.insert(it++,c);
//        }
//
//
//
//
//    return 0;
//}
