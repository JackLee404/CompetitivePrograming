#include <iostream>

using namespace std;

const int N = 1e7 + 10, mod = 1e9 + 7;

int a[N];

int solve(int x) {
	if(x <= 3) return x;
	else {
		if(!a[x]) {
			a[x] = (solve(x - 1) % mod + solve(x - 3) % mod) % mod;
			return a[x];
		} else return a[x];
	}
}

int main() {
	int x;
	cin >> x;
	cout << solve(x);
}