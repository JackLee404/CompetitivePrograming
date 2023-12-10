#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	cout << n;
	for (int i = 1; i <= n - 2; i ++) {
		cout << " " << i;
	}
	cout << " " << n - 1 << "\n";
	// sort(a.begin(), a.end());
}

int main() {
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}