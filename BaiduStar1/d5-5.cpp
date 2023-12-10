#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

int h[N], e[M], ne[M], idx;

int n, m;

bool st[N];

// 链式前向星加a->b的边
void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b; 
}

// dfs表示以u为根子树中的编号最大值
int dfs(int u) {
	int mx = u;
	st[u] = true;


	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];
		// 如果该点已经遍历过 就continue
		if (st[v]) continue;
		
		mx = max(mx, dfs(v));
	}	

	return mx;
}

int main() {
	// 初始化head
	memset(h, -1, sizeof h);

	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int u, v;

		cin >> u >> v;

		// 有向图
		add(u, v);
	}

	for (int i = 1; i <= n; i ++) {
		memset(st, false, sizeof st);
		
		cout << dfs(i) << " \n"[i == n];
	}
}