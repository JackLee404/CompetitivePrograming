#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>

using i64 = long long;

const int N = 510;

bool g[N][N];

int stop[N], dist[N], m, n;

void bfs() {
	memset(dist, -1, sizeof dist);

	std::queue<int> q1;

	q1.push(1);

	dist[1] = 0;

	while (q1.size()) {
		int t = q1.front(); q1.pop();

		if (t == n) {
			return;
		}

		for (int i = 1; i <= n; i ++) {
			if (g[t][i] && dist[i] == -1) {
				q1.push(i);
				dist[i] = dist[t] + 1;
			}
		}
	}	
}

int main() {
	std::cin >> m >> n; getchar();

	std::string line;

	while (m --) {
		getline(std::cin, line);
		std::stringstream ssin(line);

		int cnt = 0, p;

		while (ssin >> p) stop[++ cnt] = p;

		for (int i = 1; i <= cnt; i ++)
			for (int j = i + 1; j <= cnt; j ++)
				g[stop[i]][stop[j]] = true;
				// std::cout << stop[i] << " " << stop[j] << "\n";
	}

	// std::cout << g[1][5] << "\n";

	bfs();

	if (dist[n] == -1) {
		puts("No");
	} else {
		std::cout << dist[n] - 1;	
	}
}