#include <bits/stdc++.h>

using i64 = long long;

int n;

int a[3][5];

bool cmp() {
	for (int i = 1; i <= 3; i ++) {
		if (a[0][i] != a[1][i]) return a[0][i] > a[1][i];
	}
	return true;
}

int main() {
	std::cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		int c, p;
		
		std::cin >> c >> p;
		
		a[c][p] ++;
	}
	
	if (cmp()) {
		for (int i = 0; i <= 1; i ++) {
			for (int j = 1; j <= 3; j ++) {
				std::cout << a[i][j] << " \n"[j == 3];
			}
		}
        puts("The first win!");
	} else {
		for (int i = 1; i >= 0; i --) {
			for (int j = 1; j <= 3; j ++) {
				std::cout << a[i][j] << " \n"[j == 3];
			}
		}
        puts("The second win!");
	} 
}
