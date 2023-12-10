#include <bits/stdc++.h>

using i64 = long long;

const int N = 200;

int a[N], b[N];


void solve() {
	memset(a, 0, sizeof a);
	
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> b[i];

		a[b[i]] ++;
	}

	std::sort(b + 1, b + 1 + n);

	for (int i = 1; i <= n; i ++) {
		if (!b[i]) continue;
		
		if (-- a[b[i] - 1] < 0) return puts("NO"), void(0);
	}

	puts("YES");
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}