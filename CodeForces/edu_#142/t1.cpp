#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int p[N], n, m, res = 0;

int main() {
	int n, m, ans = 0;
	std::cin >> n >> m;

	for(int i = 0; i < m; i ++) {
		std::cin >> p[i];
	}

	for(int i = 1; i < 1 << m; i ++) {
		int t = 1;
		int s = 0;

		for(int j = 0; j <= m - 1; j ++) {
			if(i >> j & 1) {
				if((i64)p[j] * t > n) {
					s = -1;
					break;
				}	
				s ++;
				t *= p[j];	
			}	
		}

		if(s == -1) continue;

		if(s & 1) ans += n / t;
		else ans -= n / t;
	}

	std::cout << ans << "\n";
}