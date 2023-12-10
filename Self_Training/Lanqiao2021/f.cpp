#include <bits/stdc++.h>

using i64 = long long;

int main() {
	i64 n;

	std::cin >> n;

	int hh, mm, ss;

	i64 k = n % (24ll * 60 * 60 * 1000);

	hh = k / (60ll * 60 * 1000);

	mm = (k - hh * (60ll * 60 * 1000)) / (60 * 1000);

	ss = (k - hh * (60ll * 60 * 1000) - (60 * 1000) * mm) / 1000;

	// std::cout << hh << " " << mm << " " << ss << "\n";

	printf("%02d:%02d:%02d", hh, mm, ss);
}