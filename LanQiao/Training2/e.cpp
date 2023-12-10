#include <iostream>

using i64 = long long;

int main() {
	int w, n;

	std::cin >> w >> n;

	n %= 7;

	w += n;

	if(w > 7) w %= 7;

	std::cout << w;
}