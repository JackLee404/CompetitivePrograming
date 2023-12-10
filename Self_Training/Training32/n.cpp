#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10, M = 3e5 + 10;

int n, A, B;

int h[N], e[M], ne[M], idx;

int cnt1, cnt2;

int st[N];


void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs() {
	std::queue<int> q1;

	st[A] = 1, st[B] = 2;

	q1.push(A);
	q1.push(B);

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];
			
			if (st[v]) continue;	

			st[v] = st[u];

			q1.push(v);
		}
	}
	
	cnt1 = cnt2 = 1;
		
	for (int i = 1; i <= n; i ++) {
		if (st[i] == 1) cnt1 ++;
		else cnt2 ++;	
	}
}


int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> A >> B;

	for (int i = 1; i <= n - 1; i ++) {
		int x, y; 

		std::cin >> x >> y;

		add(x, y), add(y, x);
	}

	bfs();

	// std::cout << cnt1 << " " << cnt2 << "\n";

	puts(cnt1 >= cnt2?"Alice":"Bob");
}