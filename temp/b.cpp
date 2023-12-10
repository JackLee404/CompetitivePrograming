#include <iostream>

using namespace std;

int n, b[100010], a[100010], cnt = 0;

void dfs(int p) {
	if (p > n) return;
	dfs(p << 1);
	dfs(p << 1 | 1);
	b[p] = a[++cnt];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	dfs(1);
	for (int i = 1; i <= n; i ++) {
		cout << b[i] << " \n"[i == n];
	}
}