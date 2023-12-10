#include <iostream>
#define lowbit(x) (x & -x)
using i64 = long long;

const int N = 1e5 + 10;

int n, tr[N], a[N], ans[N];

void add(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int query(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

int main() {
	std::cin >> n;

	for (int i = 2; i <= n; i ++) std::cin >> a[i];

	for (int i = 1; i <= n; i ++) tr[i] = lowbit(i);
	
	for (int i = n; i >= 1; i --) {
		int k = a[i] + 1;
		int l = 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (query(mid) >= k) r = mid;
			else l = mid + 1;
		}
		add(r, -1);
		ans[i] = r;
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << ans[i] << " \n"[i == n];
	}
}