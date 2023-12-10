#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using i64 = long long;

const int N = 5e4 + 10;

std::vector<std::pair<int, int>> v1;

i64 f[N], ans;

bool operator <(std::pair<int, int> a, std::pair<int, int> b) {
	if(a.first + a.second == b.first + b.second) {
		return a.first < b.first;
	} else {
		return b.first + b.second > a.first + a.second;
	}
}

int main() {
	int n;
	std::cin >> n;
	
	v1.resize(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> v1[i].first >> v1[i].second;
	}

	std::sort(v1.begin() + 1, v1.end());
	

	for(int i = n; i >= 1; i --) {
		f[i] = f[i + 1] + v1[i].first;
		std::cout << v1[i].first << " " << v1[i].second << "\n";
// 		std::cout << f[i + 1] << " " << v1[i].second << "debug\n";
		ans = std::max(ans, f[i + 1] - v1[i].second);
	}

	std::cout << ans;
}