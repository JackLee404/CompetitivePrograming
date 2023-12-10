#include <iostream>

using i64 = long long;

const int N = 1e5 + 10;

std::string a[N];

int b[N];

int n;

int main() {
	std::cin >> n;

	int mi = 1;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i] >> b[i];

		if (b[i] < b[mi]) mi = i;
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << a[mi] << "\n";

		mi ++;
		
		if (mi == n + 1) mi = 1;
	}
}