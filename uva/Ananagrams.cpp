#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

void allLower(string& str){
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
}

int main (){
	string word;
	map<string, bool> dic, dicOrig;
	int n = 0, m = 0;
	while (cin >> word, word != "#"){
		dicOrig[word] = true;
		allLower(word);
		sort(word.begin(),word.end());
		if (dic.count(word))
			dic[word] = false;
		else 
			dic[word] = true;
		n++;
	}
	vector<string> anans(n);
	for (auto it : dicOrig){
		string temp = it.first;
		allLower(temp);
		sort(temp.begin(),temp.end());
		if(dic[temp]) anans[m++] = it.first;
	}
	
	sort(anans.begin(), anans.begin()+m);
	for (int i = 0; i < m; i++)
		cout << anans[i] << endl;
	
	
	return 0;
}