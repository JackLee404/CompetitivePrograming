#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 6e3 + 10;

int ha[N];

int ne[N], h[N], e[N], idx;

bool check[N];

int dp[N][2];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
	dp[u][1] = ha[u];

	for(int i = h[u]; i != -1; i = ne[i]) {
		dfs(e[i]);

		dp[u][0] += std::max(dp[e[i]][1], dp[e[i]][0]);
		dp[u][1] +=	dp[e[i]][0]; 
	}
}



int main() {
	memset(h, -1, sizeof h);

	int n;
	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> ha[i];
	}

	for(int i = 1; i <= n - 1; i ++) {
		int a, b;
		std::cin >> a >> b;
		add(b, a);
		check[a] = true;
	}

	int root = 1;

	while(check[root]) root ++;

	dfs(root);

	std::cout << std::max(dp[root][1], dp[root][0]);
}