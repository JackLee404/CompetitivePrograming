#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10;

int primes[N], cnt;

bool st[N];

std::unordered_map<int, int> hash;

void init(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

void solve(int n, int k) {
	if (!st[n]) {
		// std::cout << n << " " << k << "\n";
		hash[n] += k;
	}

	for (int i = 1; i <= cnt; i ++) {
		int v = primes[i];

		if (v > sqrt(n)) break;

		int ct = 0;

		while (n % primes[i] == 0) {
			n /= primes[i], ct ++;
		}

		std::cout << i << " " << ct * k << "\n";

		hash[i] += ct * k;
	}

	if (n) hash[n] += k;
}

int main() {
	init(1000000);

	int x;

	std::cin >> x;

	for (int i = 2; i <= x; i ++) {
		solve(i, x - i + 1);
		
		// std::cout << i << " " << x - i + 1 << "\n";
	}

	printf("f(%d)=1", x);

	for (int i = 1; i <= x; i ++) {
		if (hash[i]) {
			printf("*%d^%d", i, hash[i]);
		}
	}
}