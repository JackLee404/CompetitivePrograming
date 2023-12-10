#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

struct node {
	int ts, id;
}a[N];

int b[N];

int main() {
	int n, d, k;

	std::cin >> n >> d >> k;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i].ts >> a[i].id;
	}

	std::sort(a + 1, a + 1 + n, [](node &a, node &b){
		return a.ts < b.ts;
	});

	std::vector<int> ans;

	for(int i = 1, j = 1; i <= n; i ++) {
		while(j <= n && a[j].ts - a[i].ts < d) {
			b[a[j].id] ++;
			if(b[a[j].id] >= k) {
				ans.push_back(a[j].id);
				b[a[j].id] = -1e6;
			}
			j ++;
		}

		b[a[i].id] --;
	}

	std::sort(ans.begin(), ans.end());

	for(int i = 0; i <= (int) ans.size() - 1; i ++) {
		std::cout << ans[i] << "\n";
	}
}