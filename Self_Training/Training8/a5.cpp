#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	int ans = 0;

	for(int i = 1, j = 1; i <= n; i ++) {
		int cnt = 0, pos = -1, cnt2 = 0;
		while(j <= n && cnt2 <= m) {
			cnt += a[j], cnt2 += (1 ^ a[j]);
			if(pos == -1 && !a[j]) pos = j;
			j ++;
		}
		// std::cout << cnt << " " << pos << "\n";
		if(pos == -1) {
			break;
		}
		i = pos, j = pos + 1;
		ans = std::max(ans, cnt);
	}

	std::cout << ans << "\n";
}