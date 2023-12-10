#include <bits/stdc++.h>

using i64 = long long;

unsigned nand(i64 x, i64 y) {
	return ~(x & y);
}

int main() {
	std::cout << nand(1119, 12512513);
}