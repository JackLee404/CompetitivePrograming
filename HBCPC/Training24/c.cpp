#include <iostream>

using namespace std;

const char out[][1000] = {"You are lucky!", "Wish you good luck."};

int solve(int t) {
	int a = 0, b = 0;
	for (int i = 0; i <= 6; i ++) {
		if (i <= 2) a += t % 10;
		else b += t % 10;
		t /= 10;
	}
	return a != b;
}

int main() {
	int n; cin >> n;
	while (n --) {
		int t; cin >> t;
		cout << out[solve(t)] << "\n";
	}
}