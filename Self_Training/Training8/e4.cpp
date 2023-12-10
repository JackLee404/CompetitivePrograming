#include <iostream>
#include <vector>

using i64 = long long;

const int N = 1e3, Offset = 100;

int n, cnt = 0;

bool r[N], c[N], dig1[N], dig2[N];

std::vector<int> ans;

void dfs(int u) {
	if(u > n) {
		if(cnt < 3)
			for(int i = 0; i < ans.size(); i ++) {
				std::cout << ans[i] << " \n"[i == (int) ans.size() - 1];
			}
		cnt ++;
		return;
	}
	for(int i = 1; i <= n; i ++) {
		if(!c[i] && !dig1[Offset + i - u] && !dig2[Offset + u + i]) {
			dig1[Offset + i - u] = true;
			dig2[Offset + u + i] = true;
			c[i] = true;
			ans.push_back(i);
			dfs(u + 1);
			dig1[Offset + i - u] = false;
			dig2[Offset + u + i] = false;
			c[i] = false;
			ans.pop_back();
		}
	}
}

int main() {
	std::cin >> n;

	dfs(1);

	std::cout << cnt;
}