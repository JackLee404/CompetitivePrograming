#include <bits/stdc++.h>

using i64 = long long;

const int N = 500;

int n, e;

int en[N];

std::vector<int> g[N], ans;

bool vis[N];

void topsort() {
	std::queue<int> q1;

	for(int i = 0; i < n; i ++) {
		if(!en[i]) {
			q1.push(i);
            break;
		}
	}

	while(q1.size()) {
		int t = q1.front(); q1.pop();

		ans.push_back(t);

		// std::cout << t << "\n";

		for(auto &x: g[t]) {
            en[x] --;
			if(en[x] == 0) {
				q1.push(x);
			}
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

	for(int i = 0; i < n; i ++) {
		std::sort(g[i].begin(), g[i].end());
	}

	topsort();

	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << " ";
		vis[ans[i]] = true;
	}

	for(int i = 0; i < n; i ++) {
		if(!vis[i]) {
			std::cout << i << " ";
		}
	}
    
}