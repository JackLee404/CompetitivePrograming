#include <iostream>
#include <cstring>
#include <deque>

using i64 = long long;

const int N = 1e3 + 10, M = 2e4 + 10;

/*
	问题：
		对于任意的1~n的路径，求该路径上第k+1大的边权最小的方案
	
	二分：
		check(x) 从1~n的最少经过>x的路径边数不超过k个

	边界处理：
		如果从1到N不连通, 肯定会一直check(false) 我们让其搜到Max(L_i) + 1
		另外答案可能为0, 即不存在经过1~n超过k个的点，我们的ans会搜到0	

	复杂度
	O(m \times log(MAX(L_i)))
*/


std::deque<int> q1;

int h[N], w[M], e[M], ne[M], idx;

int dist[N];

bool st[N];

int n, p, k;

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}


bool check(int x) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	
	q1.push_back(1);

	dist[1] = 0;

	while (q1.size()) {
		int t = q1.front(); q1.pop_front();

		if (st[t]) continue;
		st[t] = true;

		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i], v = w[i] > x;
			if (dist[j] > dist[t] + v) {
				dist[j] = dist[t] + v;
				if (!v) {
					q1.push_front(j);
				} else q1.push_back(j);
			}	
		}
	}

	// std::cout << dist[n] << "\n";

	return dist[n] <= k;
}


int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> p >> k;

	for (int i = 1; i <= p; i ++) {
		int a, b, l;

		std::cin >> a >> b >> l;

		add(a, b, l);
		add(b, a, l);
	}

	int l = 0, r = 1e6 + 1;

	while (l < r) {
		int mid = l + r >> 1;

		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	if (l == 1e6 + 1) {
		std::cout << -1;
	} else std::cout << l;
}