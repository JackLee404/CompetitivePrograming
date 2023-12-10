#include <iostream>
#include <vector>

using i64 = long long;

inline int nxt() {
	int x;

	std::cin >> x;

	return x;
}


std::vector<int> con, times;


int main() {
	int n = nxt();

	con.resize(n + 1), times.resize(n + 1);

	for (int i = 1; i <= n; i ++) {
		con[i] = nxt();
	}

	for (int i = 1; i <= n; i ++) {	
		int u = i;

		while (times[con[u]] <= 1) {

			// std::cout << u << "\n";

			times[u] ++;

			if (times[u] == 2) {
				std::vector<int> v1;

				while (times[con[u]] != 3) {
					times[u] ++;

					// std::cout << u << " - \n";
					v1.push_back(u);

					u = con[u];
				}

				v1.push_back(u);

				std::cout << v1.size() << "\n";

				for (int i = 0; i < v1.size(); i ++) {
					std::cout << v1[i] << " \n"[i == (int) v1.size() - 1];
				}

				return 0;
			}

			u = con[u];
		}

		
	}
}