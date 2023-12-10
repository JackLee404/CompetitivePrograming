#include <bits/stdc++.h>

using i64 = long long;

int n;

int a[10], st[10][10];

int main() {
	for (int i = 1; i <= 6; i ++) {
		std::cin >> a[i];
		st[i][a[i]] = 1;
	}

	std::cin >> n;
	while (n --) {
		for (int i = 1; i <= 6; i ++) {
			for (int j = 6; j >= 1; j --) {
				if (st[i][j]) continue;
				st[i][j] = 1;
                if (n == 0)
				    std::cout << j << " \n"[i == 6];
				break;
			}
		}
	}
}