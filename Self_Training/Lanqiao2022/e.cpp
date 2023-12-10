#include <iostream>
#include <vector>
#define sz(x) x.size()
using i64 = long long;

const int N = 1e6 + 10, mod = 1e9 + 7;

int n, ma, mb;

int a[N], b[N];

int main() {
	std::cin >> n;

	std::cin >> ma;

	for(int i = ma; i >= 1; i --) {
		std::cin >> a[i];
	}

	std::cin >> mb;

	for(int i = mb; i >= 1; i --) {
		std::cin >> b[i];
	}

	i64 cur = 1, ans = 0;

	for(int i = 1; i <= std::max(ma, mb); i ++) {
		int dec = std::max(std::max(a[i], b[i]) + 1, 2);

		ans = (ans + (a[i] - b[i]) * cur) % mod;

		cur = (cur * dec) % mod;
	}

	std::cout << (ans + mod) % mod;
}