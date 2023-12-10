#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int n, m;
 
int p[N], sz[N];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void add(int a, int b) {
	int fa = find(a), fb = find(b);

	// std::cout << fa << " " << fb << "\n";

	if(fa == fb) return;

	p[fb] = p[fa];

	sz[fa] += sz[fb];
}

int main() {

	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;

	for(int i = 1; i <= m; i ++) {
		int x, y;

		std::cin >> x >> y;

		add(x, y);

		std::cout << sz[find(x)] << "\n";
	}
}