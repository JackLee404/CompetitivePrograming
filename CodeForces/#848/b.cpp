#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, d;
	std::cin >> n >> m >> d;

	std::vector<int> v2(n + 1), a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> v2[i];
		a[v2[i]] = i;
	}

	std::vector<int> v(m + 1);

	for(int i = 1; i <= m; i ++) {
		std::cin >> v[i];
	}

	int ans = 0;

	// auto move = [&] (int k, int st, int dir) {
	// 	while(k --) {
	// 		if(dir == -1){
	// 			std::swap(v2[st], v2[st - 1]);
	// 			std::swap(a[st], a[st - 1]);
	// 			st --;
	// 		} else if(dir == 1) {
	// 			std::swap(v2[st], v2[st + 1]);
	// 			std::swap(a[st], a[st + 1]);
	// 			st ++;
	// 		}
	// 	}
	// };

	for(int i = 1; i < m; i ++) {
		int &i1 = v[i], &i2 = v[i + 1];
		if(a[i1] < a[i2] && a[i2] <= a[i1] + d){
			int mv = a[i1] + d - a[i2] + 1;
			if(a[i2] + mv > n || a[i2 - 1]) {
				ans += a[i2] - a[i1];
				// std::cout << a[i2] - a[i1] << " " << i2 << " " << i1 << " " << "\n";
				// move(a[i2] - a[i1], a[i2], -1);
			} else{
				ans += std::min(a[i2] - a[i1], mv);
				// if(a[i2] - a[i1] <= mv) {
				// 	move(a[i2] - a[i1], a[i2], -1);
				// } else {
				// 	move(mv, a[i2], 1);
				// }
			}
		}
	}



	std::cout << ans << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}