#include <iostream>
#include <vector>
#include <cstring>
int n, m;

int dp[12][12];

int main() {
	std::cin >> n >> m;
	std::vector<std::string> v(n);
	for(auto &x: v) {
		std::string t; 
		std::cin >> t;
		v.push_back(' ' + t);
	}

	for(int i = 1; i <= 10; i ++) dp[i][0] = i;
	for(int j = 1; j <= 10; j ++) dp[0][j] = j;

	for(int i = 1; i <= m; i ++) {
		std::string t;
		int mx, cnt = 0;
		std::cin >> t >> mx;
		t = ' ' + t;
		for(auto &x: v) {
			for(int i = 1; i < x.size(); i ++) {
				for(int j = 1; j < t.size(); j ++) {
					dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1; 
					dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + (int)(x[i] != t[j]));
				}
			}
			if(dp[(int)x.size() - 1][(int) t.size() - 1] <= mx) cnt ++;
		}
		std::cout << cnt << "\n";
	}
}