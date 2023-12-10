#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10;

int primes[N], cnt;

bool st[N];


void get_prime(int n) {
	for(int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;

		for(int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true;
			if(i % primes[j] == 0) break;
		}
	}
}

int main() {
	get_prime(1000000);	
	int n;
	
	while(std::cin >> n, n) {
		for(int i = 0; i <= cnt && primes[i] - n >= 3; i ++) {
			int &k = primes[i];

			if(!st[n - k]) {
				printf("%d = %d + %d\n", n, k, n - k);
			}
		} 
	}
}