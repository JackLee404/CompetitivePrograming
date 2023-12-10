#include <iostream>
#include <cstring>
#include <cmath>
#define INF 1e20
using i64 = long long;

const int N = 200;

int n;

double d[N][N], maxd[N];

char a[N][N];

struct node {
	int x, y;
} b[N];

double calc(int i, int j) {
	double a = b[i].x - b[j].x, c = b[i].y - b[j].y;
	return sqrt(a * a + c * c);
}

void floyd() {
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			d[i][j] = (i == j)?0:INF;
		}
	}

	for (int i = 1; i <= n; i ++) {
		std::cin >> b[i].x >> b[i].y;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			std::cin >> a[i][j];
			if (a[i][j] == '1') {
				d[i][j] = calc(i, j);
			}
		}
	}

	floyd();

	double ans = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (d[i][j] != INF)
				maxd[i] = std::max(maxd[i], d[i][j]);
		}
		ans = std::max(ans, maxd[i]);
	}

	double ans2 = INF;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (d[i][j] == INF) {
				ans2 = std::min(ans2, maxd[i] + maxd[j] + calc(i, j));
			}
		}
	}

	printf("%.6lf", std::min(ans, ans2));
}