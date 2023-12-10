#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;

	std::cin >> n >> m;


	for (int i = 1; i <= n; i ++) {
		if (m <= 4) {
			if (i == n && n % 2 != 0) {
				for (int j = 1; j <= m; j ++) {
					std::cout << ((j & 1)?"x":"o");
				}
				puts("");
			} else std::cout << std::string(m, (i & 1)?'o':'x') << "\n";

			continue;
		}


		if (i == n && n % 2 != 0) {
			for (int j = 1; j <= m; j ++) {
				std::cout << ((j & 1)?"x":"o");
			}
			puts("");

			continue;
		}

		std::string t = std::string(4, (i & 1)?'o':'x') + ((i & 1)?"x":"o");

		for (int j = 1; j <= (m / 5); j ++) std::cout << t;
        
        for (int j = 0; j < m % 5; j ++) {
            std::cout << t[j];
        }

		puts("");
	}
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }	
}