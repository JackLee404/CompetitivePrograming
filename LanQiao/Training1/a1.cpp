#include <iostream>
#include <cstring>
#include <vector>
#define sz(x) (int) x.size()
#define debug(x) std::cout << "debug:" << x << "\n";

using i64 = long long;

const int N = 110, M = 1 << 10, mod = 1e4 + 7;

i64 f[N][M];
std::vector<int> state[M];
bool st[M], t1[15][110];
int n, m, p;

bool check(int c, int s1, int s2) {
	int t = s2;
	for(int i = 0; i < n; i ++) {
		int k1 = s1 >> i & 1, k2 = s2 >> i & 1;
		if(t1[i][c]) t -= (1 << i);
		else if(k2 && k1 == k2) return false;
	}
	return st[s1 | t];
}

bool check2(int c, int s1) {
	for(int i = 0; i < n; i ++) {
		int k1 = s1 >> i & 1;
		if(k1 != (int) t1[i][c]) return false;
	}
	return true;
}

int main() {
	std::cin >> n >> m >> p;

	for(int i = 0; i < p; i ++) {
		int x, y;
		std::cin >> x >> y;
		x --, y --;
		t1[x][y] = true;
	}

	for(int i = 0; i < 1 << n; i ++) {
		int cnt = 0
		bool ok = true;
		for(int j = 0; j < n; j ++) {
			if(i >> j & 1) {
				if(cnt & 1) {
					ok = false;
					break;
				} else cnt = 0;
			} else cnt ++;
		}
		if(cnt & 1) ok = false;
		st[i] = ok;
	}

	f[0][0] = 1;

	for(int i = 1; i <= m; i ++) {
		for(int j = 0; j < 1 << n; j ++) {
			if(!check2(i, j)) continue;
			for(int k = 0; k < 1 << n; k ++) {
				if(check(i, k, j)) {
					if(i == 1) std::cout << k << "\n";
					f[i][j] += f[i - 1][k];
				}
			}
		}
	}

	debug(f[1][3]);

	for(int i = 0; i <= m; i ++) {
		for(int j = 0; j < 1 << n; j ++) {
			std::cout << f[i][j] << " \n"[j == (1 << n) - 1];
		}
	}
}