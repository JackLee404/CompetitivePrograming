#include <iostream>

using namespace std;

int fac(int x) {
	if (x == 1) return 1;
	else return x * fac(x - 1);
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << fac(a +b);
}