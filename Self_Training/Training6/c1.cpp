#include <bits/stdc++.h>
#include <cctype>
using i64 = long long;

const int N = 5e6 + 10;

int primes[N], cnt;

bool st[N];

int arr[] = {2, 3, 5, 7};

void get_primes(i64 n) {
	for(i64 i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for(i64 j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true;
			if(primes[j] % i == 0) break;
		}
	}
}

bool check(i64 x) {
	i64 k = x;
	while(x > 0) {
		int k = x % 10;
		x /= 10;
		bool st = false;
		for(int i = 0; i < 4; i ++) {
			if(k == arr[i]) st = true;
		}	
		if(!st) return false;
	}

	std::string t = std::to_string(k);

	for(int i = 0; i < (int) t.size() - 1; i ++) {
		int k = (t[i] - '0') + (t[i + 1] - '0') * 10;
		if(st[k]) {
			return false;
		}
	}

	return true;
}

int main() {
	get_primes(23737);

	for(i64 i = 0; i < cnt; i ++) {
		if(check(primes[i])) {
			std::cout << primes[i] << "\n";
		}
	}
}