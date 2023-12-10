#include <bits/stdc++.h>
#include <cstring>
#define FOR(i, n) for(int i = 1; i <= n; i ++)
using i64 = long long;
const int N = 110, M = 10010;

int n, m;
int s[N], f[M];

int sg(int x) {
	if(f[x] != -1) return f[x];

	std::unordered_set<int> S;

	for(int i = 0; i < m; i ++) {
		int sum = s[i];
		if(x >= sum) S.insert(sg(x - sum));
	}

	for(int i = 0; ; i ++) {
		if(!S.count(i))
			return f[x] = i;
	}
}

int main() {
	std::cin >> m;
	for(int i = 0; i < m; i ++) std::cin >> s[i];
	std::cin >> n;

	memset(f, -1, sizeof f);

	int res = 0;

	for(int i = 0; i < n; i ++) {
		int x;
		std::cin >> x;
		res ^= sg(x);
	}
}