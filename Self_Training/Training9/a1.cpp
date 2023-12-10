#include <iostream>

using i64 = long long;

const int N = 1e3 + 10;

int f[N], f2[N], a[N], ans;

int main() {
	int n;
	std::cin >> n;

	for(int i = 1; i <= n; i ++){
		std::cin >> a[i];

		f[i] = 1;

		for(int j = 1; j < i; j ++) {
			if(a[j] < a[i]) {
				f[i] = std::max(f[i], f[j] + 1);
			}
		}
	}

	for(int i = n; i >= 1; i --) {
		f2[i] = 1;

		for(int j = n; j > i; j --) {
			if(a[j] < a[i])
				f2[i] = std::max(f2[i], f2[j] + 1);
		}

		ans = std::max(ans, f2[i] + f[i] - 1);
	}

	std::cout << ans;
}

/*
	186 186 150 200 160 130 197 220

	150 160 197 220
*/