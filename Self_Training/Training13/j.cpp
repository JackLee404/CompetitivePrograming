#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#define ff first
#define ss second

using i64 = long long;

const int N = 2e5 + 10, M = 1e5;

int n, k;

int depth[N];

void bfs() {
	std::queue<int> q1;

	q1.push(n);

	depth[n] = 0;

	while(q1.size()) {
		int t = q1.front(); q1.pop();

		if(t == k) {
			return std::cout << depth[t] << "\n", void(0);
		}

		if(depth[t + 1] == -1 && t + 1 <= M) {
			q1.push(t + 1);
			depth[t + 1] = depth[t] + 1;
		}

		if(depth[2 * t] == -1 && 2 * t <= M) {
			q1.push(2 * t);
			depth[2 * t] = depth[t] + 1;
		}

		if(depth[t - 1] == -1) {
			q1.push(t - 1);
			depth[t - 1] = depth[t] + 1;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	
	while(std::cin >> n >> k) {
		memset(depth, -1, sizeof depth);
		bfs();
	}
}