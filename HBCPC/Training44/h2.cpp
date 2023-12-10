#include <bits/stdc++.h>

using i64 = long long;

typedef long long ll;
typedef std::pair<ll, ll> pll;

int main() {
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;

	std::vector<pll> a(n), tmp;

	for (int i = 0; i < n; i ++) std::cin >> a[i].first;

	for (int i = 0; i < n; i ++) std::cin >> a[i].second;

	std::vector<ll> Sx, Sy, len;
	std::vector<pll> T;

	// ans 维护重叠部分， 答案为 sum - 2 * ans
	ll sum = 0, ans = 0;

	for (auto[x, y]: tmp) {
		sum += std::abs(x - y);
		if (x < y) tmp.emplace_back(x, y);
		else if (x > y) tmp.emplace_back(y, x);
	}
	
	std::sort(tmp.begin(), tmp.end());

	ll r = -1e18;
	// 消除正向包络关系
	for (auto x: tmp) {
		if (x.second <= r) continue;
		r = x.second;
		Sx.push_back(x.first), Sy.push_back(x.second);
		len.push_back(x.second - x.first);	
	}
}