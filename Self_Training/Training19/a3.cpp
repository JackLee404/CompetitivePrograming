#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

using i64 = long long;

int a[510];

bool st1[510], st2[510], ans[510];

std::vector<std::pair<int, int>> b[510];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;

	std::cin >> n;	

	std::vector<int> bot;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	for (int i = 1; i <= n; i ++) {
		int x;
		for (int j = i + 1; j <= n; j ++) {
			std::cin >> x;
			b[i].push_back({x, j});
			b[j].push_back({x, i});
		}
	}

	for (int i = 1; i <= n; i ++) std::sort(b[i].begin(), b[i].end(), std::greater<int>());

	int cnt = 0;



	while (cnt <= n) {
	}
}