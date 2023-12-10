#include <bits/stdc++.h>
#define FASTIO                \
    std::ios::sync_with_stdio(0); \
    std::cin.tie(0);               \
    std::cout.tie(0);
using i64 = long long;

const int N = 1e7 + 10, MAXN = 1e7 + 10;

int primes[N], cnt, pe[N];
bool st[N];

void get_primes(int n) {
	for(int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i, pe[i] = i;
		for(int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true;
			pe[primes[j] * i] = primes[j];
			if(i % primes[j] == 0) break;
		}
	}
}

void solve() {
	int x, y;
	std::cin >> x >> y;

	if(y - x == 1) {
		std::cout << "-1" << "\n";
		return;
	} else if(std::__gcd(x, y) > 1) {
		std::cout << "0" << "\n";
		return;
	}

	int mx = 0x3f3f3f3f;

	int b = y - x, cur = 0;

	// while(primes[cur] <= sqrt(b)) {
	// 	if(b % primes[cur]) {
	// 		cur ++;
	// 		continue;	
	// 	}
	// 	while(b % primes[cur] == 0) {
	// 		b /= primes[cur];
	// 	}
	// 	mx = std::min(mx, primes[cur] - x % primes[cur]);
	// 	cur ++;
	// }

	// if(b > 1) {		
	// 	mx = std::min(mx, b - x % b);
	// }

	while(b > 1) {
		mx = std::min(mx, pe[b] - x % pe[b]);
		int pp = pe[b];
		while(b % pp == 0) b /= pp;
	}

	std::cout << (mx == 0x3f3f3f3f?-1:mx) << "\n";
}

int main() {
	FASTIO;
	get_primes(10000000);	
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}