#include <iostream>
#include <unordered_map>

using i64 = long long;

const int N = 3e5 + 10;

const i64 INF = 1e18;

int x, y, z;

std::string s1;

i64 dp[N][3];

int main() {
	std::cin >> x >> y >> z;

	std::cin >> s1;

	int len = s1.size();

	s1 = '0' + s1;

	dp[0][1] = z;

	for (int i = 1; i < (int) s1.size(); i ++) {
		if (s1[i] == 'A') {
			dp[i][0] = std::min(dp[i - 1][0] + y, dp[i - 1][1] + std::min(y + z, z + x));			
			dp[i][1] = std::min(dp[i - 1][1] + x, dp[i - 1][0] + std::min(y + z, z + x));
		} else {
			dp[i][0] = std::min(dp[i - 1][0] + x, dp[i - 1][1] + std::min(y + z, z + x));
			dp[i][1] = std::min(dp[i - 1][0] + std::min(x + z, z + x), dp[i - 1][1] + y);
		}

		// std::cout << dp[i][0] << " " << dp[i][1] << "\n";
	}

	std::cout << std::min(dp[len][0], dp[len][1]);
}