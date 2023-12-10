#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define lowbit(x) (x & -x)
using i64 = long long;

const int N = 1e5 + 10;

int n, a[N], b[N], tr[N];

std::unordered_map<int, int> idx;

void add(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int query(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

int main() {
	i64 ans = 0;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> a[i], b[i] = a[i];

	std::sort(b + 1, b + 1 + n);

	for (int i = 1; i <= n; i ++) {
		idx[b[i]] = i;
	}

	for (int i = 1; i <= n; i ++) {
		ans += query(n) - query(idx[a[i]]);
		add(idx[a[i]], 1);
	}

	std::cout << ans;
}	