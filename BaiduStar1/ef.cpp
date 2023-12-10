#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt = -1;


/*
	1 2 3

	stk
	0 1 2
	1 2 3
*/

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i ++) {
		int x;

		cin >> x;

		stk[++ tt] = x;
	}

	while (tt >= 0) {
		cout << stk[tt --] << " ";
	}
}