#include <iostream>
#include <cstdio>

using i64 = long long;

int main() {
	int h, n, f;

	std::cin >> h >> n >> f;

	double k = h * 1.0 / n * (f - 1);
    

	printf("%.2lf", k);
}