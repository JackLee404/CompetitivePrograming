#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n;
	
	std::cin >> n;
	
	std::vector<int> v(n + 1);
	
	for (int i = 1; i <= n; i ++) std::cin >> v[i];
	
	int m;
	
	std::cin >> m;
	
	while (m --) {
		bool ok = true;
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			int x;
			std::cin >> x;
			if (!x) continue;
			if (x != v[i]) ok = false;
			cnt ++;
		}
		if (cnt && ok) {
			puts("Da Jiang!!!");
		} else puts("Ai Ya");
	}
}