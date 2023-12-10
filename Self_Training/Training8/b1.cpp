#include <iostream>
#include <algorithm>
#include <vector>

using i64 = long long;

const int N = 2e6 + 10;

int a[N], p[N];

int n, m;

int main() {
	std::cin >> n >> m;

	for(int i = 1; i <= m; i ++) {
		std::cin >> p[i] >> a[i];
	}

	std::vector<int> pos(m + 1);

	for(int i = 1; i <= m; i ++) {
		pos[i] = i;
	}

	
	std::sort(pos.begin() + 1, pos.end(), [](int x, int y) {
		return p[x] < p[y];
	});


	i64 cost = 0, now = 0;

	// for(int i = 1; i <= m; i ++) {
	// 	std::cout <<p[pos[i]] << "\n";
	// }

	for(int i = 1; i <= m; i ++) {
		if(now >= n) {
			break;
		}

		int k = std::min((n - now), (i64) a[pos[i]]);

		cost += k * p[pos[i]];

		now += k;
	}

	std::cout << cost;
}