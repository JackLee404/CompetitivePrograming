#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <stack>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

int a[N][N], n;

void dfs(int x, int y, int dir, int len) {
	if (len == 1)
		return;
	if (dir == 0) { // 向右

		while (y < len) a[x][++y] = 1;
		dfs(x, y, 1, len - 1);

	} else if (dir == 1) { // 向下

		while (x < len) a[++x][y] = 1;
		dfs(x, y, 2, len);

	} else if (dir == 2) { // 向左

		while (y > n - len + 1) a[x][--y] = 1;	
		dfs(x, y, 3, len - 1);

	} else if (dir == 3) { // 向上

		while (x > n - len + 1) a[--x][y] = 1;
		dfs(x, y, 0, len);

	}
}

int main() {
	cin >> n;
	dfs(1, 0, 0, n);
	int mx, my, tx, ty;
	mx = my = n/2 + 1;
	tx = mx, ty = my + 1;
	a[mx][my] = a[mx-1][my];

	while (ty <= n && ty <= n) {
		swap(a[tx][ty], a[tx + 1][ty + 1]);
		tx ++, ty ++;
	}


	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}