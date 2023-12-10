#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int n;

int a[N], dep[N];

std::unordered_map<int, std::vector<int>> idx;

int bfs() {
	std::queue<int> q;

	q.push(0);

	dep[0] = 0;

	while(q.size()) {
		int t = q.front(); q.pop();

		if(t == n - 1) {
			return dep[t];
		}

		if(dep[t + 1] == -1) {
			dep[t + 1] = dep[t] + 1;
			q.push(t + 1);
		}

		if(t - 1 >= 0 && dep[t - 1] == -1) {
			dep[t - 1] = dep[t] + 1;
			q.push(t - 1);
		}

		for(auto &x: idx[a[t]]) {
			if(dep[x] == -1) {
				dep[x] = dep[t] + 1;
				q.push(x);
			}
		}
	}

	return -1;
}

int main() {
	memset(dep, -1, sizeof dep);

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];

		idx[a[i]].push_back(i);
	}


	std::cout << bfs();
}