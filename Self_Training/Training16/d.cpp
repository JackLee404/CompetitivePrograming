#include <iostream>
#include <cmath>

using i64 = long long;


int main() {	
	int cnt = 0;
	i64 n;

	while(std::cin >> n) {
		while(n != 1) {
			std::cout << n << "\n";
			n = floor(sqrt(n / 2 + 1 * 1.0));
			cnt ++;
		}

		std::cout << ":" << "------------\n";
	}
}