#include <iostream>

using i64 = long long;

const int N = 5e3 + 10;

int q[N], hh = 0, tt = -1, siz = 0;

bool vis[N];

int main() {
	int n, m;

	std::cin >> m >> n;

	int ans = 0;

	for(int i = 1; i <= n; i ++) {
		int x;
		std::cin >> x;

		if(vis[x]) continue;

		ans ++;
 
		if(siz == m) {
			vis[q[hh]] = false;
			vis[x] = true;
			q[++ tt] = x;
			hh ++;
		} else {
			q[++ tt] = x;
			vis[x] = true;	
			siz ++;
		}
	}

	std::cout << ans;
}