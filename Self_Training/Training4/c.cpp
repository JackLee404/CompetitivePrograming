#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a[3], b[3];

	for(int i = 0; i < 3; i ++) {
		std::cin >> a[i] >> b[i];
	}

	// 存在连个点的横坐标相同
	int m1 = -1, m2 = -1;
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			if(i == j) continue;
			if(a[i] == a[j]) m1 = i, m2 = j;			
		}
	}

	if(m1 == -1) {
		std::cout << "YES\n";
		return;
	}

	int a1 = -1, a2 = -1;
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			if(i == j) continue;
			if(b[i] == b[j]) a1 = i, a2 = j;
		}
	}

	if(a1 == -1) {
		std::cout << "YES\n";
		return;
	}	

	std::cout << "NO\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}