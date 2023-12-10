#include <bits/stdc++.h>
#define ff first
#define ss second

using i64 = long long;

const int N = 1e5 + 10;

int n;

std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> mp;

std::map<std::pair<int, int>, int> mp2;

int get(int x, int y) {
	return x * x + y * y;
}

int gcd(int a, int b) {
	return b? gcd(b, a % b): a;
}

int main() {
	int sum = 0;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		int x, y, p;

		std::cin >> x >> y >> p;

		sum += p;

		std::pair<int, int> t;

		mp2[{x, y}] = p;

		if (!x || !y) {
			t = {x, y};
		} else t = {y / std::abs(gcd(x, y)), x / std::abs(gcd(x, y))};

		mp[t].push_back({x, y});
	}

	int ans1 = 0, ans2 = 0;

	for (auto x: mp) {
		std::vector<std::pair<int, int>> &v = x.ss;

		std::sort(v.begin(), v.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
			return a < b;
		});

		for (int i = 0, j = 0; i < v.size(); i ++) {
			if (mp2[v[i]] >= 2) {
				ans2 ++;
			} else {
				ans2 ++;
				j = i;
				while (j < v.size() && mp2[v[j]] == 1) {
					j ++;
				}
				j --;
				i = j;
			}
		}
	}

	std::cout << sum << " " << ans2 << "\n";
}