#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

const int N = 2e5 + 10;

int n;

int a[N], prefix[N];

int idx, ne[N * 40][3], val[N * 40];

void insert(int x, int l){
	int p = 0;
	for(int i = 29; i >= 0; i --) {
		int u = x >> i & 1;
		if(!ne[p][u]) ne[p][u] = ++ idx;
		p = ne[p][u];
	}
	val[p] = l;
}

std::pair<int, int> query(int x, int r) {
	int p = 0, k = 0;
	for(int i = 29; i >= 0; i --) {
		int u = x >> i & 1;
		if(!ne[p][!u]) p = ne[p][u];
		else p = ne[p][!u], k += (1ll<<i);
	}
	return std::make_pair(val[p], k);
}

int main() {
	std::cin >> n;

	insert(0, 0);

	// rep(i, 1, n) {
		
	// }

	rep(i, 1, n) {
		std::cin >> a[i];
		prefix[i] = a[i] ^ prefix[i - 1];
		
		std::pair<int, int> ans = query(prefix[i], i);

		std::cout << ans.second << " " << ans.first + 1 << "\n";
		
		insert(prefix[i], i);
	}

	std::cout << (1024&(~(1<<10))) << "\n";
}