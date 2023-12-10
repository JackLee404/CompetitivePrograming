#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;
typedef int mat;
#define int long long

const int N = 2e5 + 10, M = 8e6 + 10;

int n;

int a[N], prefix[N];

int idx, ne[M][3], val[M];

void insert(int x, int l){
	int p = 0;
	for(int i = 30; i >= 0; i --) {
		int u = x >> i & 1;
		if(!ne[p][u]) ne[p][u] = ++ idx;
		p = ne[p][u];
	}
	val[p] = l;
}

std::pair<int, int> query(int x) {
	int p = 0, k = 0;
	for(int i = 30; i >= 0; i --) {
		int u = x >> i & 1;
		if(ne[p][u^1]) p = ne[p][u^1], k += (1<<i);
		else p = ne[p][u];
	}
	return std::make_pair(val[p], k);
}

mat main() {
	std::cin >> n;

	insert(0, 0);

	rep(i, 1, n) {
		std::cin >> a[i];
		prefix[i] = a[i] ^ prefix[i - 1];
		insert(prefix[i], i);
		std::pair<int, int> ans = query(prefix[i]);
		std::cout << ans.second << " " << ans.first + 1 << "\n";
	}

	return 0;
}