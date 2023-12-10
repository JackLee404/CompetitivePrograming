#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int a[N], sum, ans = 0;

bool vis[N];

void dfs(int cnt, int now) {
	if(cnt == 3) {

		// std::cout << now << "\n";
		
		if(sum - now == now) {
			ans ++;
		}
		return;
	}

	for(int i = 1; i <= 6; i ++) {
		if(vis[i]) continue;

		vis[i] = true;

		dfs(cnt + 1, now + a[i]);

		vis[i] = false;
	}
}


int main() {
	int t;

	std::cin >> t;

	while(t --) {
		memset(vis, false, sizeof vis);
		sum = 0;
		
		ans = 0;

		for(int i = 1; i <= 6; i ++) {
			std::cin >> a[i];

			sum += a[i];
		}

		// std::cout 

		dfs(0, 0);

		puts(ans?"yes":"no");
	}
}