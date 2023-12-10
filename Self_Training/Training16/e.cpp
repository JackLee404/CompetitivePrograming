#include <iostream>
#include <cmath>
#include <queue>
#include <unordered_map>
#define act(x) floor(sqrt(x / 2 + 1 * 1.0))
using i64 = long long;

const int N = 2e5 + 10;

int n;

i64 w[N], b[N], ans = 0;

std::vector<i64> v1[N];

std::priority_queue<i64> h1;


int main() {
	std::cin >> n;

	// v1.resize(n);

	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];

		i64 t = w[i];

		std::vector<i64> &v = v1[i];


		while (t != 1) {
			v1[i].push_back(t);
			t = act(t);	
		}

		v1[i].push_back(1);
		
		for (int j = 0; j < v1[i].size(); j ++) {
			std::cout << v1[i][j] << " \n"[j == (int) v1[i].size() - 1];
		}
	}

	int ans = 0;

	for (int i = 1, j = i + 1; i <= n; i ++) {
		std::cout << j << "\n";
		
		bool ok = true;

		int pi = 0, pj = 0, k;
		for (; pi < v1[i].size() && pj < v1[j].size(); pi ++, pj ++) {
			if (v1[i][pi] == v1[j][pj]) {
				ok = true;
				k = v1[i][pi];
				break;	
			}
		}
		if (ok) {
			j ++, pj = 0;
			ok = false;
			while (j <= n && ok) {
				for (; pj < v1[j].size(); pj ++) {
					if (v1[j][pj] == k) {
						ok = true;
						break;
					}
				}
				j ++, pj = 0;
				ans += std::max(0, pj - 1);
			}
		} else {
			ans += std::max(0, (int) v1[i].size() - 1);
		}
	}

	std::cout << ans;
}