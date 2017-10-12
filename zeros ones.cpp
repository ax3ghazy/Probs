#include <iostream>
using namespace std;

int main (){
	unsigned int  x, a, b;
	while (cin >> x, x){
		a = b = 0;
		int index = 1;
		while (x){
			unsigned int ls = x & -x;
			x -= ls;
			if(index++%2) a+=ls;
			else b+= ls;
		}
		cout << a << ' ' << b << endl;
	}
	
	
	
	
	return 0;
}