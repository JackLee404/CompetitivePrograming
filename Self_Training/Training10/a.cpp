#include <iostream>

using i64 = long long;

const int N = 1e5 + 10;

int a[N], pre[N];

int main() {
	int n, m;
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		std::cin >> pre[i];
	}


	while(m --) {
		int l, r, c;
		
		std::cin >> l >> r >> c;

		pre[l] += c;
		pre[c + 1] -= c;
	}

	for(int i = 1; i <= n; i ++) {
		pre[i] += pre[i - 1];

		std::cout << pre[i] << " \n"[i == n];
	}
}