#include <bits/stdc++.h>

using i64 = long long
const int N = 1e5 + 10

int n, m;

int sum[N], sum2[N], s1;

struct node {
	int l, r, e;
}a[N], b[N];

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i].l >> a[i].r >> a[i].e;

		b[i].l = a[i].l, b[i].r = a[i].r, b[i].e = a[i].e;

		s1 += a[i].e;
	}

	std::sort(a + 1, a + 1 + n, [](node a, node b) {
		return a.r < b.r;
	});

	std::sort(b + 1, b + 1 + n, [](node a, node b) {
		return a.l < b.l;
	});

	int ans = 0;
	
	a[0].r = a[0].l = a[0].e = 0;

	a[m + 1].r = a[m + 1].l = a[m + 1].e = 0;

	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i].e;
	}

	for (int i = n; i >= 1; i --) {
		sum2[i] = sum2[i + 1] + b[i].e;
	}

	sum2[0] = sum2[1];
	sum[n + 1] = sum[n];

	for (int i = 1; i <= m; i ++) {	
		int l = 0, r = n + 1;

		int s1 = 0;
		
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (a[mid].r < i) l = mid;
			else r = mid - 1;
		}

		s1 += sum[l];

		l = 0, r = n + 1;

		while (l < r) {
			int mid = l + r >> 1;
			if (b[mid].l > i) r = mid;
			else l = mid + 1;
		}

		s1 += sum2[l];

		ans = std::max(ans, s1);
	}

	std::cout << ans;
}