#include <iostream>

using namespace std;

int out(double a, double b) {
	if (a == b)
		return 0;
	else if (a > b)
		return 1;
	else
		return 2;
}

int main() {
	int n, k, a, b; cin >> n >> k >> a >> b;
	cout << out((n - 1) * 1.0  / b, (n - 1) * 1. 0 / a);
}