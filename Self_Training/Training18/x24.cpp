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
	i64 ans = 0, k;

	std::cin >> n >> k;

	for (int i = 1; i <= n; i ++) std::cin >> a[i], b[i] = a[i];

	std::sort(b + 1, b + 1 + n);

	std::cout << b[k];
}	