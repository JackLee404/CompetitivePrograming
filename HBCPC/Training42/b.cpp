#include <bits/stdc++.h>

const int N = 1e3 + 10;

int n, m;

int a[N], h[N];

void out(int x, int y) {
	printf("Don't take %d at %d!\n", x, y);
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	while (m --) {
		int t, k; std::cin >> t >> k;
		while (k --) {
			int x; std::cin >> x;
			if(h[x] != -1 && a[x] != -1 && std::abs(t - h[x]) < a[x]) {
				out(x, t);
				continue;
			}
			h[x] = t;
		}
	}
}