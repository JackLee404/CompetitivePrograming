#include <iostream>
#include <cmath>

using i64 = long long;

const int N = 1e5 + 10;

std::string a[N];

int b[N];

int n;

int main() {
	int n;
	std::string t;

	std::cin >> n;

	t = std::to_string(n);

	for (int i = 8; i >= 3; i --) {
		if (n >= pow(10, i)) {
			t = t.substr(0, (int) t.size() - (i - 2)) + std::string(i - 2, '0');
			break;
		}
	}

	// std::cout << std::string(3, '0') << "\n";

	std::cout << t;
}