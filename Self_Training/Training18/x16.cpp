#include <iostream>
#include <vector>
#include <unordered_map>

using i64 = long long;

const int N = 1e5 + 10;

int n, m;

std::vector<int> v1[N], arr;

int pos[N]; 
i64 sum[N];

bool st[N];

void dfs(int i) {
	arr.push_back(i);
	for (auto &x: v1[i]) {
		if (!st[x]) {
			st[x] = true;
			dfs(x);
		}
	}	
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i < n; i ++) {
		int a, b;
		
		std::cin >> a >> b;

		v1[a].push_back(b);
		v1[b].push_back(a);
	}

	
}