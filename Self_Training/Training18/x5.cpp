#include <iostream>
#include <iomanip>
#include <cmath>
using i64 = long long;

int main() {
	double n, d1, d2;

	std::cin >> n >> d1 >> d2;

	float t1 = (55 - (n - d1 / 8)) * 6.8;
	float t2 = (55 - (n - d2 / 8)) * 6.2;

	// std::cout << t1 << " " << t2 << "\n";

	if (std::abs(t1 - t2) >= 10) {
		std::cout << (t2>t1?"A ":"B ") << std::fixed << std::setprecision(1) << std::abs(t1 - t2);
	} else {
		std::cout << (d1<d2?'A':'B');
	}
}