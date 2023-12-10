#include <bits/stdc++.h>
#define ff first
#define ss second
using i64 = long long;

typedef std::pair<i64, i64> PII;

const int N = 200;

int n, ans;

std::set<PII> s1;

PII a[N];

bool st[N];

std::map<PII, int> mp;

i64 gcd(i64 a, i64 b) {
	return b?gcd(b, a % b):a;
}

PII calc(PII a, PII b) {
	PII t = {a.ss - b.ss, a.ff - b.ff};

	if (t.ff == 0) return {0, 1};	
	else if (t.ss == 0) return {1, 0};
	else {
		if (t.ff < 0) t.ff *= -1, t.ss *= -1;

		i64 m = std::__gcd(std::abs(t.ff), std::abs(t.ss));
		
		return {t.ff / m, t.ss / m};
	}
}


int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		PII t; std::cin >> t.ff >> t.ss;
		s1.insert(t);
	}

	n = 0;

	for (auto it: s1) {
		a[++ n] = it;
	}

	for (int i = 1; i <= n; i ++) {
		if (st[i]) continue;

		st[i] = true;

		// std::cout << "point" << i << "\n";

		for (int j = i + 1; j <= n; j ++) {
			if (st[j]) continue;					

			PII res = calc(a[i], a[j]);

			// std::cout << res.ff << " " << res.ss << "\n";

			mp[res] ++;
		}

		ans ++;

		if (mp.size()) {
			int mx = -1;
			PII mi;
			for (auto it = mp.begin(); it != mp.end(); it ++) {
				PII t = (*it).ff;
				int val = (*it).ss;

				if (val > mx) {
					mx = val;
					mi = t;
				}
			}

			for (int j = i + 1; j <= n; j ++) {
				if (st[j]) continue;

				PII res = calc(a[i], a[j]);

				if (res == mi) {
					st[j] = true;
				}
			}
		}
	}

	std::cout << ans;
}