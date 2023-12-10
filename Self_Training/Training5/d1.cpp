#include <iostream>

const int N = 1e6 + 10;

int primes[N], cnt, st[N];

int qucik_pow(int a, int b) {
	int t = 1;
	while(b > 0) {
		if(b & 1) a *= t;
		t *= a;
		b>>=1;
	}
	return a;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << qucik_pow(a, b) << std::endl;
}