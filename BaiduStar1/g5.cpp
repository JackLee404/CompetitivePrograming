#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], h[N], idx;


// vector<int> g[N];

// h[a] 为刚刚代码中的head, 这里就相当于在h[a]中模拟链表

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}


int main() {
	// 把h数组 初始化为-1, 相当于刚才head = -1
	memset(h, -1, sizeof h);

	// 0, -1, 0x3f memset 允许初始化的值

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		int u, v;

		cin >> u >> v;

		add(u, v);
	}
}