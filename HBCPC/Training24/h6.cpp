#include <iostream>
#include <vector>
#include <cmath>
typedef int bint;
#define int long long
using namespace std;

int gcd(int a, int b) {
	return b == 0?a:gcd(b, a % b);
}

int ex_gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, x, y);
	int tmp = x;
	x = y, y = tmp - a / b * y;
	return d;
}

bint main() {
	int t; cin >> t;
	while(t --) {
		int a, b; cin >> a >> b;
		int x, y; ex_gcd(a, b, x, y);
		int b1 = a / gcd(a, b);
		int t = ceil(x * 1.0 / b1);
		cout << x - b1 * t << "\n";
	}
}