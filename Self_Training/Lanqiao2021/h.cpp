#include <iostream>
#include <algorithm>

using i64 = long long;

const int N = 1e5 + 10;

int n, m;
int a[N], diff[N];

// 第i个数a + i

void sort1(int l, int r, int x) {
	if(x)
		std::sort(a + l, a + r + 1);
	else
		std::sort(a + l, a + r + 1, std::greater<int>());
}

int main() {	
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) a[i] = i;

	for(int i = 1; i <= m; i ++) {
		int x, y;

		std::cin >> x >> y;

		if(x) sort1(y, n, x);
		else sort1(1, y, x);

		// for(int i = 1; i <= n; i ++) {
		// 	std::cout << a[i] << " \n"[i == n];
		// }
	}

	for(int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}
}