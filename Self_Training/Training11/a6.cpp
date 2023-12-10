#include <iostream>
#include <vector>
#include <utility>
#define ff first
#define ss second

using i64 = long long;

const int mod = 9901;

int ans = 0;

std::vector<std::pair<int, int>> v1;

int quick_pow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = ((i64)res * a) % mod;
		a = ((i64)a * a) % mod;
		b >>= 1;	
	}

	return res;
}

void prime_factors(int x) {
	for(int i = 2; i <= x / i; i ++) {
		int cnt = 0;

		while(x && x % i == 0) {
			x /= i;
			cnt ++;	
		}	

		v1.push_back({i, cnt});
	}

	if(x) v1.push_back({x, 1});
}

int solve(int a, int b) {
	if(b == 0) return a;
	if(b % 2 == 0) {
		return (i64)solve(a, b / 2 - 1) * quick_pow(a, b / 2) % mod;	
	} else {
		return ((i64)solve(a, b - 1) + quick_pow(a, b)) % mod;
	}
}

int main() {
	int a, b;

	std::cin >> a >> b;

	prime_factors(a);

	i64 ans = 1;

	for(int i = 0; i < v1.size(); i ++) {
		ans = (i64)ans * solve(v1[i].ff, v1[i].ss) % mod;
	}

	std::cout << ans;
}