#include <bits/stdc++.h>
#define maxn 1414214
using i64 = long long;

const int N = 1414214 + 1e3;

i64 b[N];

/*
	a[i] 第i个区间的和
	b[i] 表示前i个区间的和
*/


i64 f(i64 ft, i64 ed, i64 num) {
	return (ft + ed) * num / 2;
}

i64 b_search(i64 x) {
	i64 l, r;

	l = 1, r = maxn;

	while (l < r) {
		i64 mid = l + r >> 1;

		if (x <= f(1, mid, mid)) r = mid;
		else l = mid + 1;
	}

	i64 k = x - f(1, l - 1, l - 1);

	return b[l - 1] + f(1, k, k);
}

void solve() {
	i64 x, y, sum = 0;

	std::cin >> x >> y;

	i64 t1 = b_search(x), t2 = b_search(y);

	std::cout << b_search(y) - b_search(x - 1) << "\n";
}

int main() {
	int _;

	std::cin >> _;

	for (int i = 1; i <= maxn; i ++) {
		b[i] += b[i - 1] + f(1, i, i);
	}

	while (_ --) {solve();}		
}