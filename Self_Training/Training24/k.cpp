#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF 0x3f3f3f3f
typedef std::pair<int, int> PII;
using i64 = long long;

const int N = 600;

int n;

std::string sex[N];

int d[N][N];

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			d[i][j] = (i == j)?0:INF;
		}
	}

	for (int i = 1; i <= n; i ++) {
		std::cin >> sex[i];

		int k;

		std::cin >> k;

		while (k --) {
			int a, b;
			scanf("%d:%d", &a, &b);
			d[i][a] = b;
		}
	}

	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	std::vector<std::pair<int, int>> v1, v2;

	for (int i = 1; i <= n; i ++) {
		if (sex[i] == "F") continue;
		int t = 0;
		for (int j = 1; j <= n; j ++) {
			if (sex[i] == sex[j]) continue;

			t = std::max(t, d[j][i]);
		}
		v1.push_back({t, i});
	}

	for (int i = 1; i <= n; i ++) {
		if (sex[i] == "M") continue;
		int t = 0;
		for (int j = 1; j <= n; j ++) {
			if (sex[i] == sex[j]) continue;

			t = std::max(t, d[j][i]);
		}
		v2.push_back({t, i});
	}


	std::sort(v1.begin(), v1.end(), [](PII a1, PII b1) {
		if (a1.ff == b1.ff) {
			return a1.ss < b1.ss;
		} else {
			return a1.ff < b1.ff;
		}
	});

	std::sort(v2.begin(), v2.end(), [](PII a1, PII b1) {
		if (a1.ff == b1.ff) {
			return a1.ss < b1.ss;
		} else {
			return a1.ff < b1.ff;
		}
	});

	for (int i = 0; i < v1.size(); i ++) {
		if (!i) {
			std::cout << v2[i].ss;
		} else {
			if (v2[i].ff == v2[0].ff) {
				std::cout << " " << v2[i].ss;
			}
		}
	}

	puts("");

	for (int i = 0; i < v1.size(); i ++) {
		if (!i) {
			std::cout << v1[i].ss;
		} else {
			if (v1[i].ff == v1[0].ff) {
				std::cout << " " << v1[i].ss;
			}
		}
	}	
}