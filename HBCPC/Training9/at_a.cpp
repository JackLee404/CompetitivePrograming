#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, k, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i ++) {
		int c;
		cin >> c;
		if (c == x) k = i;
	}
	cout << k << endl;
}