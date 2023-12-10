#include <bits/stdc++.h>

using i64 = long long;

const int N = 200;

i64 primes[N], st[N], cnt;

void seive(int n) {
	for(int i = 2; i <= n; i ++) {
		if(!st[i]) {
			primes[cnt ++] = i;
			for(int j = i + i; j <= n; j += i) {
				st[j] = true;
			}
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> a(n);

	for(auto &x: a) {
		std::cin >> x;
	}

	std::sort(a.begin(), a.end());

	for(int i = 0; i < a.size(); i ++) {
		if(i && a[i] == a[i - 1]) {
			puts("NO");
			return;
		}
	}

	for(int i = 0; primes[i] <= n / 2; i ++) {

		std::vector<i64> sc(primes[i], 0);

		for(auto &x: a) {
			sc[x % primes[i]] ++;
			// std::cout << x % primes[i] << " ";
		}	

		// std::cout << "\n";

		if(*std::min_element(sc.begin(), sc.end()) >= 2) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	seive(100);
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}