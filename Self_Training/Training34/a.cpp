#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 10;

struct node {
	int s, a, e;

	void input() {
		std::cin >> s >> a >> e;
	}

	void out() {
		std::cout << s << " " << a << " " << e << "\n";
	}
};

int n;

node a[N];

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		a[i].input();
	}


	std::sort(a + 1, a + n + 1, [](node a, node b){
		return a.s + a.a + a.e < b.s + b.a + b.e;
	});

	i64 sum = 0, t = 0;

	for (int i = 1; i <= n; i ++) {
		if (i == 1) {
			sum += a[i].s + a[i].a;
		} else {
			sum += t + a[i].s + a[i].a;
		}

		t += a[i].s + a[i].a + a[i].e;

		// a[i].out();
	}

	std::cout << sum;
}