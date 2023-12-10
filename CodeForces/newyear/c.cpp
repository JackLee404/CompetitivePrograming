#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void solve() {
	vector<int> a, b;
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		a.push_back(i), b.push_back(i);
	}
	reverse(b.begin(), b.end());
	int gap = k - 1;
	for (int i = 1; i <= n; i ++) {
		if (gap) {
			cout << a.back(), a.pop_back(), gap --;
		} else {
			gap = k - 1;
			cout << b.back(), b.pop_back();
		}
		cout << " \n"[i == n];
	}
}

int main() {
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}