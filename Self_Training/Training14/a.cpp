#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <utility>
#define INF 0x3f3f3f3f
#define ff first
#define ss second

using i64 = long long;

const double EPS = 1e-8;


std::set<std::pair<double, double>> tot;

void calc(int x1, int y1, int x2, int y2, double &k, double &b) {
	k = (y2 - y1) * 1.0 / (x2 - x1);
	b = (y2 - k * x2) * 1.0;
}

int main() {
	int a, b;

	std::cin >> a >> b;

	// a = 20, b = 21;

	for(int x1 = 0; x1 < a; x1 ++) {
		for(int y1 = 0; y1 < b; y1 ++) {
			std::pair<int, int> s1 = {x1, y1};

			for(int x2 = 0; x2 < a; x2 ++) {
				for(int y2 = 0; y2 < b; y2 ++) {
					std::pair<int, int> s2 = {x2, y2};

					if(s1 == s2 || s1.ff == s2.ff) continue;

					double k, b;

					calc(s1.ff, s1.ss, s2.ff, s2.ss, k, b);

					tot.insert({k, b});
				}
			}
		}
	}

	// int ans = 1;

	// auto last = tot.begin();

	// for(auto it = tot.begin(); it != tot.end(); it ++) {
	// 	if(it != tot.begin()) {
	// 		if(std::abs((*it).ff - (*last).ff) > EPS || std::abs((*it).ss - (*last).ss) > EPS) {
	// 			ans ++;
	// 		}
	// 	}
	// 	last = it;
	// }

	std::cout << tot.size() + a << "\n";

	// std::cout << ans + a;
}