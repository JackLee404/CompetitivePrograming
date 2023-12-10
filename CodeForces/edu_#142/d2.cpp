#include <bits/stdc++.h>

using i64 = long long;

const int N = 5e5 + 10;

int nex[N][15], cnt;
bool exist[N];  // 该结点结尾的字符串是否存在

void insert(std::vector<int> &t, int l) {  // 插入字符串
	int p = 0;
	for (int i = 1; i <= l; i++) {
	  int c = t[i];
	  if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
	  p = nex[p][c];
	}
	exist[p] = 1;
}

int query(std::vector<int> &t, int l) {  // 查找字符串
	int p = 0;
	for (int i = 1; i <= l; i++) {
	  int c = t[i];
	  if (!nex[p][c]) return i - 1;
	  p = nex[p][c];
	}
	return l;
}

void solve() {
	int n, m;

	std::cin >> n >> m;

	for(int i = 0; i < cnt; i ++) {
		memset(nex[i], 0, sizeof nex[i]);
	}

	cnt = 0;

	std::vector<std::vector<int>> a(n, std::vector<int>(m + 1));

	for(int i = 0; i < n; i ++) {
		std::vector<int> t(m + 1);
		for(int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
			t[a[i][j]] = j;
		}
		insert(t, m);
	}

	for(int i = 0; i < n; i ++) {
		std::cout << query(a[i], m) << " \n"[i == n - 1];
	}
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}