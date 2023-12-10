#include <bits/stdc++.h>

using i64 = long long;

i64 p;

int fast_pow(int a, int k) {
	int res = 1;
	while(k){
		if(k & 1) res = (i64)res * a % p;
		a = (i64)a * a % p;
		k >>= 1;
	}
	return res;
}

int C(int a, int b) {
	int res = 1;
	for(int i = 1, j = a; i <= b; i ++, j --) {
		res = (i64)res * j % p;
		res = (i64)res * fast_pow(i, p - 2) % p;
	}
	return res;
}

int lucas(i64 a, i64 b) {
	if(a < p && b < p) return C(a, b);
	return (i64)C(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main() {
	int n;
	std::cin >> n;
	while(n --) {
		i64 a, b;
		std::cin >> a >> b >> p;
		std::cout << lucas(a, b) << "\n";
	}
}