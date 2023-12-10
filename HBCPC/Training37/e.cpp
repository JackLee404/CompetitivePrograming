#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3;

const double EPS = 1e-6;

int n, m, h, sum;

int a[N];

int main() {
	std::cin >> n >> m >> h;

	for (int i = 1; i <= m; i ++) {
		std::cin >> a[i], sum += a[i];
	}

	if (sum < n) {
		return puts("-1"), 0;	
	}

	
}