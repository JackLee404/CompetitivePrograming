#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using i64 = long long;

/*
	性质： 
	每盏灯最多操作一次
	
	思路： 先枚举第一行的状态, 然后进行递归

	第一行的状态确定了，第二行的状态也自然确定了！
*/

char a[10][10], tmp[10][10];

int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

int ans;

void flip(char &x) {
	x = (x == '0'?'1':'0');
}

bool check(int x, int y) {
	return x >= 1 && x <= 5 && y >= 1 && y <= 5;
}

void four_flip(int x, int y) {
	flip(tmp[x][y]);

	for(int j = 0; j <= 3; j ++) {
		int tx = x + dx[j], ty = y + dy[j];
		if(check(tx, ty)) {
			flip(tmp[tx][ty]);
		}
	}
}

bool check(char a[]) {
	for(int i = 1; i <= 5; i ++) {
		if(a[i] != '1') return false;
	}
	return true;
}

void dfs(int u, int cnt) {

	for(int j = 1; j <= 5; j ++) {
		if(tmp[u - 1][j] != '1') {
			four_flip(u, j);
			cnt ++;

			if(cnt > 6) return;
		}
	}

	if(u == 5) {
		if(check(tmp[u])) {
			ans = std::min(ans, cnt);
		}
		return;
	}


	dfs(u + 1, cnt);
}

void solve() {
	ans = INF;
	
	for(int i = 1; i <= 5; i ++) {
		for(int j = 1; j <= 5; j ++) {
			std::cin >> a[i][j];
		}
	}

	for(int s = 0; s < (1<<5); s ++) {
		memcpy(tmp, a, sizeof a);

		int cnt = 0;

		for(int j = 0; j < 5; j ++) {
			if(s >> j & 1) {
				cnt ++;
				four_flip(1, j + 1);
			}
		}

		// tmp[1][6] = '\0';

		// printf("%s\n\n", tmp[1] + 1);
		dfs(2, cnt);
	}


	std::cout << (ans <= 6?ans:-1) << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}