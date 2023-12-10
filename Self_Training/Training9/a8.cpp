#include <bits/stdc++.h>
#include <cstring>

using i64 = long long;

const int N = 200;

int n;

char a[N][N], ans[N][N], tmp[N][N];

char t[] = "yizhong";

int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

int dig[] = {1, -1};

bool check(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void search(int x, int y) {
	if(a[x][y] != 'y') {
		return;
	}

	for(int i = 0; i <= 3; i ++) {
		memcpy(tmp, ans, sizeof tmp);

		int tx = x + dx[i], ty = y + dy[i];

		int pos = 1;

		if(check(tx, ty)) {
			tmp[x][y] = 'y';
			while(check(tx, ty) && pos <= 6 && a[tx][ty] == t[pos]) {
				tmp[tx][ty] = t[pos];
				tx += dx[i], ty += dy[i];
				pos ++;
			}
			if(pos > 6) {
				// std::cout << x << " " << y << " " << dx[i] << " " << dy[i] << "\n";
				memcpy(ans, tmp, sizeof ans);
			}
		}
	}

	for(int i = 0; i <= 1; i ++) {
		for(int j = 0; j <= 1; j ++) {
			memcpy(tmp, ans, sizeof tmp);

			int tx = x + dig[i], ty = y + dig[j];

			int pos = 1;

			if(check(tx, ty)) {
				tmp[x][y] = 'y';
				while(check(tx, ty) && pos <= 6 && a[tx][ty] == t[pos]) {
					tmp[tx][ty] = t[pos];
					tx += dig[i], ty += dig[j];
					pos ++;
				}
				if(pos > 6) {
					// std::cout << x << " " << y << " " << dx[i] << " " << dy[i] << "\n";
					memcpy(ans, tmp, sizeof ans);
				}
			}
		}
	}
}

int main() {
	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		scanf("%s", a[i] + 1);
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			search(i, j);
		}
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(!ans[i][j]) std::cout << "*";
			else std::cout << ans[i][j];
		}
		std::cout << "\n";
	}	
}