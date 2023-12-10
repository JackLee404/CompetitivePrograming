#include <bits/stdc++.h>
#define ff first
#define ss second

using i64 = long long;

typedef std::pair<int, int> PII;

const int N = 2e5 + 10;

int n;

std::pair<int, int> a[N], b1[N], b2[N];

int p1[N], p2[N];

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i].ff;
		b1[i].ff = b2[i].ff = a[i].ff;
	}	

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i].ss;
		b1[i].ss = b2[i].ss = a[i].ss;
	}


	std::sort(b1 + 1, b1 + 1 + n, [](PII a, PII b) {
		return a.ff < b.ff;
	});

	std::sort(b2 + 1, b2 + 1 + n, [](PII a, PII b) {
		return a.ss < b.ss;
	});

	p1[n + 1] = -0x3f3f3f3f;

	for (int i = n; i >= 1; i --) {
		p1[i] = std::max(p1[i + 1], b1[i].ss);
	}

	p2[n + 1] = -0x3f3f3f3f;

	for (int i = n; i >= 1; i --) {
		p2[i] = std::max(p2[i + 1], b2[i].ff);
	}

	int ans = 0;

	for (int i = 1; i <= n; i ++) {
		int l = 1, r = n;

		bool ok1 = true, ok2 = true;

		while (l < r) {
			int mid = l + r >> 1;
			if (b1[mid].ff > a[i].ff) r = mid;
			else l = mid + 1;
		}

		if (b1[l].ff > a[i].ff) {
			if (p1[l] > a[i].ss) ok1 = false;
		}

		l = 1, r = n;

		while (l < r) {
			int mid = l + r >> 1;
			if (b2[mid].ss > a[i].ss) r = mid;
			else l = mid + 1;
		}

		if (b2[l].ff > a[i].ss) {
			if (p2[l] > a[i].ff) ok2 = false;
		}


		if (! (!ok1 || !ok2)) ans ++;
	}

	std::cout << ans;
}