#include <bits/stdc++.h>

using i64 = long long;

const int N = 5400;

int n, r;

int rcd[N][N], pre[N][N];

int main() {

	std::cin >> n >> r;

	r = std::min(r, 5001);
	
	for(int i = 1; i <= n; i ++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		x ++, y ++;

		rcd[x][y] = w;
	}	

	int ans = 0;

	for(int i = 1; i <= 5001; i ++) {
		for(int j = 1; j <= 5001; j ++) {
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + rcd[i][j] - pre[i - 1][j - 1];
		}	
	}

	for(int x1 = r; x1 <= 5001; x1 ++) {
		for(int y1 = r; y1 <= 5001; y1 ++) {
			int k = pre[x1][y1] - pre[x1 - r][y1] - pre[x1][y1 - r] + pre[x1 - r][y1 - r];
			ans = std::max(ans, k);
		}
	}

	std::cout << ans;
}
/*

右边的后缀=左边的后缀，

同时左边的某一部分的后缀=左边某一部分的前缀。



所以，应该存在左边某一部分的前缀=右边某一部分的后缀，这个长度是从左边的这部分找到的

*/