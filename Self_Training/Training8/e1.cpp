#include <iostream>

using i64 = long long;

const int N = 5e5 + 10;

int cnt;

struct node {
	int a, b, g, k;
}v[N];

int main() {
	int n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		int a, b, g, k;
		std::cin >> a >> b >> g >> k;
		v[++cnt] = {a, b, g, k};
	}

	int x, y, ans = -1;

	std::cin >> x >> y;

	for(int i = 1; i <= cnt; i ++) {
		node &t = v[i];

		if(x <= t.a + t.g && x >= t.a && y >= t.b && y <= t.b + t.k) {
			ans = i;
		}
	}

	std::cout << ans;
}