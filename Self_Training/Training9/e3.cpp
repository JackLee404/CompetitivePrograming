#include <bits/stdc++.h>


using i64 = long long;

const int N = 1e5 + 10;

int a[N], pre[N];

int cnt[N], ans;

int main() {
	int n, k;

	std::cin >> n >> k;

	cnt[0] = 1;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		pre[i] = pre[i - 1] + a[i];

		if(pre[i] >= k)
			ans += cnt[pre[i] % k];

		cnt[pre[i] % k] ++;
	}


	std::cout << ans;
}