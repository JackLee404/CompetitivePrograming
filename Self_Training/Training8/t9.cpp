#include <iostream>

using i64 = long long;

const int N = 20;

int v1[N][4], w[N], lm[4];

int n, a, b, c;

int main() {
	std::cin >> n >> lm[1] >> lm[2] >> lm[3];

	int ans = 0;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= 3; j ++) {
			std::cin >> v1[i][j];
		}
		std::cin >> w[i];
	}

	for(int i = 0; i < (1ll<<n); i ++) {
		int a[4], now = 0;
		a[1] = a[2] = a[3] = 0;
		for(int j = 0; j < n; j ++) {
			if(i >> j & 1) {
				for(int k = 1; k <= 3; k ++) {
					a[k] += v1[j][k];
					if(a[k] > lm[k]) {
						break;
					}
				}
				now += w[j];
			}
		}
		ans = std::max(ans, now);
	}

	std::cout << ans;
}