#include <iostream>
#include <vector>
#include <cmath>
#define ff first
#define ss second

using i64 = long long;

const int N = 1e3 + 10;

std::string aim = "DSWYBS";

char a[N][N];

int n, m;

bool ok;

int d[] = {0, 1, -1};

std::vector<std::pair<int, int>> v1, ans;

void dfs(int x, int y, int pos) {

	if(ok) return;


	for(int i = 0; i <= 2; i ++) {
		for(int j = 0; j <= 2; j ++) {
			if(d[i] == 0 && d[j] == 0) continue;

			int tx = x + d[i], ty = y + d[j];

			

			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == aim[pos]) {
			
				v1.push_back({tx, ty});

				// std::cout << tx << " " << ty << " " << pos << "\n";

				if(pos == 5) {
					ans = v1;
					ok = true;
					return;
				}

				dfs(tx, ty, pos + 1);

				v1.pop_back();
			}
		}
	}
}

int main() {
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
		}
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(a[i][j] == 'D') {
				v1.push_back({i, j});

				// std::cout << i << " " << j << "\n";
				dfs(i, j, 1);
				
				v1.clear();
			}

			if(ok) break;
		}
	}

	if(!ok) {
		std::cout << "DSWYBS";
	} else {
		std::cout << ans[0].ff - 1 << " " << ans[0].ss - 1 << "\n";

		std::cout << ans[5].ff - 1 << " " << ans[5].ss - 1 << "\n";

		std::cout << ans[0].ff + ans[0].ss + ans[5].ff + ans[5].ss - 4;
	}

	// for(auto &t1: ans) {
	// 	std::cout << t1.ff << " " << t1.ss << "\n";
	// }
}