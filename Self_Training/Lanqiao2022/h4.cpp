#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#define sz(x) x.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i --)

using i64 = long long;

const int mod = 1e9 + 7, N = 5e4 + 10;

// mp存储当前点所包含的雷 (因为雷的数量可能大于1，值为vector)
std::map<std::pair<int, int>, std::vector<int>> mp;

// node 存储当前引爆雷所联通的其他雷（存的为下标）
std::vector<int> node[N];

// 存储引爆雷和其他雷
std::pair<std::pair<int, int>, int> p1[N], p2[N];

// vis数组对下标打标记
bool vis[N];

i64 dist(int x1, int y1, int x2, int y2) {
	return (i64)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int n, m;

int dfs(int u) {
	if(vis[u]) {
		return 0;
	}

	vis[u] = true;

	int ans = 1;

	for(auto &v: node[u]) {
		ans += dfs(v);
	}

	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n >> m;

	rep(i, 1, n) {
		int x, y, z;

		std::cin >> x >> y >> z;

		mp[{x, y}].pb(i);
		p1[i] = {{x, y}, z};
	}

	rep(i, 1, m) {
		int x, y, z;

		std::cin >> x >> y >> z;

		p2[i] = {{x, y}, z};
	}

	int ans = 0;

	// 先预处理所有圆心所包含的半径内的点
	rep(i, 1, n) {
		i64 x = p1[i].ff.ff, y = p1[i].ff.ss, r = p1[i].ss;

		rep(dx, -10, 10) {
			rep(dy, -10, 10) {
				i64 tx = x + dx, ty = y + dy;

				if(dist(x, y, tx, ty) <= r * r) {
					for(auto &j: mp[{tx, ty}]) {
						node[i].pb(j);
					}
				}
			}
		}
	}

	// 对每个引爆雷圆心所包含的点进行遍历
	rep(i, 1, m) {
		i64 x = p2[i].ff.ff, y = p2[i].ff.ss, r = p2[i].ss;

		rep(dx, -10, 10) {
			rep(dy, -r, 10) {
				i64 tx = x + dx, ty = y + dy;

				if(dist(x, y, tx, ty) <= r * r) {
					for(auto &j: mp[{tx, ty}]) {
						ans += dfs(j);
					}
				}
			}
		}
	}

	std::cout << ans;
}