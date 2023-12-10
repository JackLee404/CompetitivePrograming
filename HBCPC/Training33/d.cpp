#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

int n, a[N], card[N][140], idx[N], cnt, tot;

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	for (int i = 1; ; i ++) {
		if (i > n) i = 1;

		if (n - tot <= 1) break;

		if (idx[i] == a[i] * 10) {
			continue;
		}

		card[i][++ idx[i]] = ++ cnt;
		
		if (idx[i] == a[i] * 10) tot ++;
	}

	for (int i = 1; i <= n; i ++) {
		if (idx[i] != a[i] * 10) {
			cnt --;
			while (idx[i] != a[i] * 10) {
				card[i][++ idx[i]] = (cnt += 2);
			}
		}
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << "#" << i << "\n";
		for (int j = 1; j <= a[i] * 10; j ++) {
			std::cout << card[i][j] << " \n"[j % 10 == 0];
		}
	}
}