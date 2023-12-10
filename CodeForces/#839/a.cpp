#include <iostream>

using namespace std;

int main() {
	int _;
	cin >> _;
	while (_ --) {
		string a;
		cin >> a;
		cout << a[0] - '0' + a[2] - '0' << endl;
	}
}