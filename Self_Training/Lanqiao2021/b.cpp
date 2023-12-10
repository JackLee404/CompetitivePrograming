#include <bits/stdc++.h>
#define ff first
#define ss second

using i64 = long long;

const double EPS = 1e-8;

std::set<std::pair<int, int>> s1;

std::set<std::pair<double, double>> s2;

void calc(int x1, int y1, int x2, int y2, double &k, double &b) {
	k = (y1 - y2) * 1.0 / (x1 - x2);

	b = y2 - x2 * k; 
}

int main() {
	int n, m;

	std::cin >> n >> m;

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			s1.insert({i, j});
		}
	}

	for(auto &t1: s1) {
		for(auto &t2: s1) {
			int x1 = t1.ff, y1 = t1.ss, x2 = t2.ff, y2 = t2.ss;

			double k, b;

			if(x1 == x2) continue;

			calc(x1, y1, x2, y2, k, b);

			s2.insert({k, b});
		}
	}	

	// std::cout << s2.size() + n;

	int ans = 1;

	auto last = s2.begin();

	for(auto it = s2.begin(); it != s2.end(); it ++) {
		if(it != s2.begin()) {
			double k1 = (*last).ff, b1 = (*last).ss;

			double k2 = (*it).ff, b2 = (*it).ss;

			if(std::abs(k1 - k2) > EPS || std::abs(b1 - b2) > EPS)
				ans ++;
		}
		last = it;
	}

	std::cout << ans + n;
}