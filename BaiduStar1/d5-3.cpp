#include <iostream>

using namespace std;

int count[10];

void solve(int x) {
	if (!x) return count[x] ++, void(0);

	while (x) {
		count[x % 10] ++;
		x /= 10;
	}
}

int main() {
	int l, r;

	cin >> l >> r;

	while (l <= r) {
		solve(l ++);
	}

	for (int i = 0; i <= 9; i ++) {
		cout << count[i] << " \n"[i == 9];
	}
}