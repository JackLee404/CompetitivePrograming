#include <iostream>
#include <cstdio>
#include <cmath>

using i64 = long long;

int main() {
	double n, d1, d2;

	std::cin >> n >> d1 >> d2;

	double t1 = (55 - (n - d1 / 8)) * 6.8;
	double t2 = (55 - (n - d2 / 8)) * 6.2;

	if (n < d1 / 8 || n < d2 / 8) {
		printf("%c", (d1 < d2?'A':'B'));
		return 0;
	}

	if (fabs(t1 - t2) >= 10) {
		printf("%c %.1f", (t1 < t2?'A':'B'), std::abs(t1 - t2));
	} else {
        printf("%c", (d1 < d2?'A':'B'));
    }
}