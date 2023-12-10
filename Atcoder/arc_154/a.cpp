#include <iostream>
#include <cctype>

using i64 = long long;

const int mod = 998244353;

std::string a, b;

i64 ans = 1e15;

int n;

void dfs(std::string a, std::string b, int u) {
	if(u >= n) {
		i64 a1 = stoi(a), a2 = stoi(b);
		ans = std::min(ans, (a1 * a2));
		return;
	}
	
	std::swap(a[u], b[u]);
	dfs(a, b, u + 1);

	std::swap(a[u], b[u]);
	dfs(a, b, u + 1);
}

int main() {
	std::cin >> n >> a >> b;

	dfs(a, b, 0);

	std::cout << ans % mod;
}