#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	if (a[1] != 1) {
		k -= (a[1] - 1);
	}
	if (k < 0) {
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= n; i ++) {
		if (a[i] != a[i - 1]) {
			if (abs(a[i] - a[i - 1]) != 1) {
				k -= (a[i] - a[i - 1] - 1);
			}
		}
	}
	if (k < 0)  {
		cout << 0;
	}
}