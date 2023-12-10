#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e4 + 10;

std::vector<int> v1, v2;

int f[N];

int main() {
	int n;

	std::cin >> n;	

	v1.resize(n + 1), v2.resize(N);

	for(int i = 1; i <= n; i ++) {
		int x;
		std::cin >> v1[i] >> x;
		v2[v1[i]] = x;
	}

	std::sort(v1.begin() + 1, v1.end());

	int ans = 0;

	for(int i = 1; i <= n; i ++) {

		f[i] = 1;

		for(int j = 1; j < i; j ++) {
			if(v2[v1[j]] < v2[v1[i]]) {
				f[i] = std::max(f[i], f[j] + 1);	
			}
		}

		ans = std::max(ans, f[i]);
	}

	std::cout << ans;
}