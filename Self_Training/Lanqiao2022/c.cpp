#include <iostream>

using i64 = long long;

int main() {
	i64 a, b, n;

	std::cin >> a >> b >> n;

	i64 k = n / (5 * a + 2 * b) * 7, t = n % (5 * a + 2 * b);

	// std::cout << t << "\n";

	if(t) {
		if(t <= 5 * a) {
			if(t % a == 0) {
				k += (t / a);
			} else {
				k += (t / a) + 1;
			}
		} else {
			k += 5;
			
			t -= 5 * a;

			if(t % b == 0) {
				k += (t / b);
			} else {
				k += (t / b) + 1;
			}
		}
	}

	std::cout << k;
}