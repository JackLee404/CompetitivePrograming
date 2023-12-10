#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

long long fast_pow(long long a, double n) {
	if (n == 1) return a;
	long long t = fast_pow(a, n / 2);
	if (n % 2 == 1) return a * t;
	else return t * t;
}

int main() {
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}