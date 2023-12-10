#include <iostream>
#define PI 3.14
using i64 = long long;

int main() {
	double r, h;

	std::cin >> r >> h;

	r *= 0.01, h *= 0.01;

	double s = 2 * 3.14 * (r * r) * h;

	s *= 1000;
	// std::cout << s << "\n";

	double sum = 0;
	int cnt = 0;

	while (sum < 15) {
		sum += s;
		cnt ++;
	}

	std::cout << cnt;
}