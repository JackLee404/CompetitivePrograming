#include <iostream>
#include <iomanip>

using i64 = long long;

int main() {
	// int h, n, f;
	double h, n, f;
	
	std::cin >> h >> n >> f;

// 	f --;

	std::cout << std::fixed << std::setprecision(2) << h * 1.0 / n * (f - 1);
}