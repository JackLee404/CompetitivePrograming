#include <iostream>
#include <vector>

using i64 = long long;

const int N = 6000;

int g[N], st[N], num[N], n, m, cnt;

int f[2][N][N];

std::vector<int> state[N];


bool check(int x) {
	for(int j = 0; j < m - 1; j ++) {
		if((x >> j & 1) && ((x >> j + 1 & 1) || (x >> j + 2 & 1)))
			return false;
	}
	return true;
}

int count(int x) {
	int res = 0;
	for(int j = 0; j < m; j ++) {
		res += (x >> j & 1);
	}

	return res;
}

int main() {
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < m; j ++) {
			char c;
			std::cin >> c;

			if(c == 'H') g[i] += 1 << j;
		}
	}

	for(int i = 0; i < (1 << m); i ++) {
		if(check(i)) {
			st[++ cnt] = i;
			num[cnt] = count(i);
		}
	}

	for(int i = 1; i <= cnt; i ++) {
		for(int j = 1; j <= cnt; j ++) {
			if(st[i] & st[j]) continue;

			state[i].push_back(j);
		}
	}

	for(int i = 1; i <= n + 2; i ++) {
		for(int j = 1; j <= cnt; j ++) {
			if(st[j] & g[i]) continue;

			for(auto &x: state[j]) {
				if(st[x] & g[i - 1]) continue;

				for(auto &y: state[x]) {
					if(st[y] & st[j]) continue;
					
					f[i & 1][j][x] = std::max(f[i & 1][j][x], f[i - 1 & 1][x][y] + num[j]);
				}
			}
		}
	}

	std::cout << f[n + 2 & 1][1][1];
}