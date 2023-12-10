#include <bits/stdc++.h>
#define ff first
#define ss second
using i64 = long long;

/*
	a_i * a_j = b_i + b_j

	a_i == a_j
*/

const int N = 635, M = 2e5 + 10;

int f[N][M];

i64 a[M], b[M];

void solve() {
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i ++) std::cin >> a[i];

	for (int i = 0; i < n; i ++) std::cin >> b[i];

	i64 t = 0;

	int lim = sqrt(2 * n);

	for (int i = 0; i < n; i ++) {
		if (a[i] > lim) continue;

		i64 k = a[i] * a[i] - b[i];

		if (k >= 1 && k <= n) t += f[a[i]][k];

		f[a[i]][b[i]] ++;
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 1; j <= lim && j < a[i] && j * a[i] <= 2 * n; j ++) {
			if (a[i] * j - b[i] >= 1 && j * a[i] - b[i] <= n)
				t += f[j][a[i] * j - b[i]];
		}
	}

	std::cout << t << "\n";

	for (int i = 0; i < n; i ++) {
		if (a[i] <= lim)
			f[a[i]][b[i]] = 0;
	}

	if (1 != 1) puts("");
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}	
}