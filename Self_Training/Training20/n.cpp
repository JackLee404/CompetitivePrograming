#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using i64 = long long;

const int N = 5e5 + 10;

i64 a[N], b[N];

int n;

std::unordered_map<i64, int> pos;

int tr[N];

void add(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) {
		tr[i] += c;
	}
}

int query(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) {
		res += tr[i];
	}
	return res;
}

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		b[i] = a[i];
	}

	std::sort(b + 1,  b + 1 + n);

	for (int i = 1; i <= n; i ++) {
		pos[b[i]] = i;
	}

	i64 ans = 0;

	for (int i = 1; i <= n; i ++) {
		ans += query(n) - query(pos[a[i]]);
		add(pos[a[i]], 1);
	}

	std::cout << ans;
}