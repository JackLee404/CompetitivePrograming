#include <bits/stdc++.h>

using i64 = long long;

const int N = 30;

int n, m;

bool d[N][N];

void one_floyd(int u, int v) {	
	// for (int k = 0; k < n; k ++) {
	// 	for (int i = 0; i < n; i ++) {
	// 		for (int j = 0; j < n; j ++) {
	// 			d[i][j] |= d[i][k] && d[k][j];
	// 		}
	// 	}
	// }

	for (int i = 0; i < n; i ++) {
		if (d[i][u]) d[i][v] = 1; 
		if (d[v][i]) d[u][i] = 1;
		for (int j = 0; j < n; j ++) {
			if (d[i][u] && d[v][j]) {
				d[i][j] = 1;
			}
		}
	}
}

int check() {
	for (int i = 0; i < n; i ++) {
		// std::cout << d[i][i] << " \n"[i == n - 1];
		if (d[i][i])
			return 2;
	}


	for (int i = 0; i < n; i ++)
		for (int j = 0; j < i; j ++)
			if (!d[i][j] && !d[j][i])
				return 0;

	return 1;
}

int main() {
	while (std::cin >> n >> m, n || m) {
		memset(d, 0, sizeof d);
		
		int type = 0, cnt = 0;

		for (int i = 1; i <= m; i ++) {
			std::string t;
			
			std::cin >> t;

			int a = t[0] - 'A', b = t[2] - 'A';

			if (!type) {
				d[a][b] = 1;
			
				one_floyd(a, b);
			
				type = check();

				// std::cout << type << "\n";
				
				if (type) cnt = i;	
			}	
		}

		std::string ans;

		for (int i = 0; i < n; i ++) ans.push_back(i + 'A');

		if (!type) puts("Sorted sequence cannot be determined.");
		else if (type == 2) printf("Inconsistency found after %d relations.\n", cnt);
		else {
			std::sort(ans.begin(), ans.end(), [](char a, char b) {
				return d[a - 'A'][b - 'A'];
			});
			printf("Sorted sequence determined after %d relations: %s.\n", cnt, ans.c_str());
		}
	}
}