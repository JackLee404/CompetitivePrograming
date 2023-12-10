#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ff first
#define ss second

using i64 = long long;

const int N = 2e5 + 10, M = 4e5 + 10;

int n;

int h[N], ne[M], e[M], idx;

std::pair<int, int> deg[N];

bool st[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n;

	for (int i = 1; i <= n - 1; i ++) {
		int x, y;
		
		std::cin >> x >> y;

		add(x, y), add(y, x);

		deg[x].ss ++, deg[y].ss ++;

		deg[i].ff = i;
	}

	deg[n].ff = n;

	std::sort(deg + 1, deg + 1 + n, [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.ss > b.ss;
	});


	int sum = n;

	std::vector<int> res;

	for (int i = 1; i <= n; i ++) {
		if (st[deg[i].ff]) continue;

		int cost = 1;
		
		if (deg[i].ss > 2) {
			st[deg[i].ff] = true;
			for (int j = h[deg[i].ff]; ~j; j = ne[j]) {
				if (!st[e[j]])
					cost ++, st[e[j]] = true;
			}

			res.push_back(deg[i].ss);
			
			sum -= cost;
		}

		// std::cout << cost << "\n";
	}

	for (int i = 0; i < sum / 3; i ++) {
		res.push_back(2);	
	}

	std::sort(res.begin(), res.end());


	for (int i = 0; i < (int) res.size(); i ++) {
		std::cout << res[i];
		if (i != (int) res.size() - 1) std::cout << " ";
	}
	
}