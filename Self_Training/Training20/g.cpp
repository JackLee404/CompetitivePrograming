	#include <bits/stdc++.h>

	using i64 = long long;

	std::map<std::string, int> mp;

	int n, ans = 6, step;

	bool ok;

	char a[20][20], b[20][20];

	int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};


	void cg(char & c) {
		if (c == '0') c = '1';
		else c = '0';
	}

	void flip(int x, int y) {
		cg(b[x][y]);

		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];

			if (tx >= 1 && tx <= 6 && ty >= 1 && ty <= 6) {
				cg(b[tx][ty]);
			}
		}
	}


	void out() {
		for (int i = 1; i <= 5; i ++) {
			for (int j = 1; j <= 5; j ++) {
				std::cout << b[i][j];
				if (j == 5) puts("");
			}
		}

		puts("");
	}

	void dfs(int u) {
		if (u == 6) {
			bool ok2 = true;
			// out();
			for (int i = 1; i <= 5; i ++) {
				if (b[5][i] != '1') ok2 = false;
			}

			if (ok2) {
				ans = std::min(step, ans);
				ok = true;
			}

			return;
		}

		for (int i = 1; i <= 5; i ++) {
			if (b[u - 1][i] == '0') {
				flip(u, i);
				step ++;

				if (step > 6) {
					return;
				}
			}
		}

		dfs(u + 1);
	}


	void solve() {

		for (int i = 1; i <= 5; i ++) {
			for (int j = 1; j <= 5; j ++) {
				std::cin >> a[i][j];
			}
		}

		ok = false;
		ans = 0x3f3f3f3f;

		for (int i = 0; i < (1 << 5); i ++) {
			memcpy(b, a, sizeof a);
			step = 0;
			for (int j = 0; j < 5; j ++) {
				// char &c = b[1][j + 1];
				if (i >> j & 1) {
					flip(1, j + 1);
					step ++;
				}

				// out();
			}

			dfs(2);
		}

		if (ok) {
			std::cout << ans << "\n";
		} else {
			std::cout << "-1\n";
		}
	}

	int main() {
		std::cin >> n;

		while (n --) {
			solve();
		}
	}