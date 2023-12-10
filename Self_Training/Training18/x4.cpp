#include <iostream>
#include <vector>
#include <queue>
using i64 = long long;

const int N = 1e5 + 10;

int n, e;

std::vector<int> g[N];

int en[N];

void topsort() {
	std::priority_queue<int> q1;

	for (int i = 0; i < n; i ++) {
		if (!en[i]) q1.push(i);
	}

	while(q1.size()) {
		int t = q1.top(); q1.pop();

		std::cout << t << " ";

		for (auto v: g[t]) {
			if (-- en[v] == 0) q1.push(v);
			// std::cout << en[v] << "\n";
		}
	}
}

int main() {
	std::cin >> n >> e;

	for (int i = 1; i <= e; i ++) {
		int a, b;
		std::cin >> a >> b;
		
		g[a].push_back(b);

		en[b] ++;
	}

	topsort();
}