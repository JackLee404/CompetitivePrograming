#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include <cstring>
#define ff first
#define ss second
#define act(x) floor(sqrt(x / 2 + 1 * 1.0))
using i64 = long long;
const int N = 2e5 + 10;

int n;

i64 a[N], ans;

struct node {
	int l, r;
	i64 w;

	bool operator<(node a) const {
		if (this->w != a.w)
			return this->w < a.w;
		return this->r < a.r;
	}

	void prt() {
		std::cout << l << " " << r << " " << w << "\n";
	}
};

// std::priority_queue<std::pair<i64, int>> h1;
std::priority_queue<node> h2;

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(0);
	// std::cout.tie(0);
	
	std::cin >> n;


	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		// std::cin >> a[i];
		if (a[i] > 1)
			h2.push({i, i, a[i]});
	}

	while (h2.size()) {
		auto t = h2.top(); h2.pop();

		// t.prt();

		// if (act(t.w) != 1) {
		// 	node tmp = t;
		// 	t.w = act(t.w);
		// 	h2.push(tmp);
		// }

		while (h2.size() && h2.top().w == t.w && (h2.top().r == t.l - 1)) {
			auto tmp = h2.top(); h2.pop();
			t.l --;
		}

		if (act(t.w) != 1) {
			node tmp = t;
			tmp.w = act(t.w);
			h2.push(tmp);
		}

		ans ++;
	}

	std::cout << ans;
}