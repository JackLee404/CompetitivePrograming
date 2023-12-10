#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#define sz(x) (int)x.size()
#define ff first
#define ss second

using i64 = long long;

const int N = 200;

int w, h, n, r;

std::vector<std::pair<int, int>> v1;

bool vis[N][N], vis2[N][N];

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
} 

int main() {
	std::cin >> w >> h >> n >> r;

	int ans = 0;

	for(int i = 1; i <= n; i ++) {
		int x, y;

		std::cin >> x >> y;

		if(!vis[x][y]) v1.push_back({x, y}), vis[x][y] = true;
	}

	// std::sort(v1.begin(), v1.end());

	for(int i = 0; i < sz(v1); i ++) {	
		int tx = v1[i].ff, ty = v1[i].ss;

		for(int j = 0; j <= h; j ++) {
			for(int k = 0; k <= w; k ++) {
				if(vis2[j][k]) continue;
				if(dist(tx, ty, j, k) <= r * r) ans ++, vis2[j][k] = true;
			}
		}
	}

	std::cout << ans;
}