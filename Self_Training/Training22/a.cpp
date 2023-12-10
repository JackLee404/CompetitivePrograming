#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define debug(x) std::cout << x << "\n"
using i64 = long long;

const int N = 2000;

int n, m, d[N][N];

int main() {
	while (true) {
		std::cin >> n;
		if (!n) break;

		std::cin >> m;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				d[i][j] = (i == j)?0:0x3f3f3f3f;
			}
		}

		for (int i = 1; i <= m; i ++) {
			int a, b, t;

			std::cin >> a >> b >> t;

			d[a][b] = d[b][a] = std::min(d[a][b], t);
		}

		for (int k = 0; k < n; k ++) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < n; j ++) {
					d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		i64 ans = 0x3f3f3f3f, mx = 0;

		for (int i = 0; i <= n - 1; i ++) {
			i64 t = 0;
			for (int j = 0; j <= n - 1; j ++) {
				t += d[i][j];

				if (d[i][j] == 0x3f3f3f3f) {
					t = -1;
					break;	
				}
			}

			if (t <= ans) {
				ans = t;
				mx = i;
			}

			// std::cout << t << "\n";
		}

		if (ans == -1) {
			std::cout << -1;
		} else {
			std::cout << mx;
		}
		puts("");
	}
}