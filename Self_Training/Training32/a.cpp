#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10, M = 3e5 + 10;

int n, A, B;

int h[N], e[M], ne[M], idx;

int cnt1, cnt2;

bool st[N];


void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void act(int u, std::queue<int> &q, int &cnt) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (st[v]) continue;

		st[v] = true;

		q.push(v);

		cnt ++;
	}
}


void bfs() {
	std::queue<int> q1, q2;

	q1.push(A), q2.push(B);

	st[A] = true, st[B] = true;

	cnt1 = cnt2 = 1;
	
	while (q1.size() || q2.size()) {

		if (q1.size()) {
			int v1 = q1.front();

			q1.pop();

			act(v1, q1, cnt1);
		}

		if (q2.size()) {
			int v2 = q2.front();

			q2.pop();

			act(v2, q2, cnt2);
		}
		
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

	puts(cnt1 >= cnt2?"Alice":"Bob");
}