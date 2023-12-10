#include <iostream>
#include <vector>
#include <cmath>

using i64 = long long;

void solve(int x, int y, int z) {
	for(int i = 1; i < 105; i ++) {
		if(i % 3 == x && i % 5 == y && i % 7 == z) {
			std::cout << i << "\n";
			return;
		}
	}
}

int main() {
	int x, y, z;

	while(std::cin >> x >> y >> z, x && y && z) {
		solve(x, y, z);
	}
}