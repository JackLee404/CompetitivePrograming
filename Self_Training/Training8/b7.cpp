#include <bits/stdc++.h>

using i64 = long long;

const int N = 300;

int a[N], b[N];

int rel[5][5] = {{0, -1, 1, 1, -1}, {0, 0, -1, 1, -1}, {0, 0, 0, -1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}};

void init() {
	// rel[0] = {0, -1, 1, 1, 0};
	// rel[1] = {0, 0, -1, 1, -1};
	// rel[2] = {0, 0, 0, -1, 1};
	// rel[3] = {0, 0, 0, 0, 1};
	// rel[4] = {0, 0, 0, 0, 0};

	for(int i = 0; i <= 4; i ++) {
		for(int j = 0; j <= 4; j ++) {
			if(i > j && rel[j][i]) {
				rel[i][j] = rel[j][i] == -1?1:-1;
			}
		}
	}
}

int main() {
	init();
	int n, na, nb;

	int sa, sb;

	sa = sb = 0;

	std::cin >> n >> na >> nb;

	for(int i = 1; i <= na; i ++) {
		std::cin >> a[i];
	}

	for(int i = 1; i <= nb; i ++) {
		std::cin >> b[i];
	}

	for(int k = 1, p1 = 1, p2 = 1; k <= n; k ++, p1 ++, p2 ++) {
		if(p1 > na) p1 = 1;
		if(p2 > nb) p2 = 1;

		if(a[p1] == b[p2]) {
			continue;
		} else {
			if(rel[a[p1]][b[p2]] == 1) sa ++;
			else sb ++;
		}
		
	}

	std::cout << sa << " " << sb;
}