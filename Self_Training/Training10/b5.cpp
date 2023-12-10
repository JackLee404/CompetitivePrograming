#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
#define FOR2(i, j, k) for(int i = j; i >= k; i --)
using i64 = long long;

const int N = 1e8 + 10;

i64 a[N], pre[N], n, c;
i64 ans;

void dfs(i64 cur, i64 idx) {
	if(cur + pre[idx] <= ans) return;
	
	ans = std::max(ans, cur);

	if(!idx) return;

	if(cur + a[idx] <= c)
		dfs(cur + a[idx], idx - 1);

	dfs(cur, idx - 1);
}

void solve() {
	std::cin >> n >> c;
	

	FOR(i, 1, n) {
		std::cin >> a[i];

		if(a[i] > c) {
			n = i - 1;
			break;
		}

		pre[i] = pre[i - 1] + a[i];
	}

	dfs(0, n);


	std::cout << ans;
}

int main() {
	int _ = 1;

	// std::cin >> _;

	while(_ --) {
		solve();
	}
}