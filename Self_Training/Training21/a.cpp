#include <iostream>

using i64 = long long;

int main() {
	int n = 10000;

	int sum = 0;

	while (n >= 600) {
		n -= 300;	
		sum += 120;
	}
		
	std::cout << sum + n / 10;
}