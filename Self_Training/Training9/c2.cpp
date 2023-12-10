#include <bits/stdc++.h>

using i64 = long long;

/*
	a_i 为奇数， 并且a_i 小于前面的任意数
*/

void solve() {
	int n;

	std::cin >> n;

	std::string a, b;

	std::cin >> a >> b;

	for(int i = 0; i < n; i ++) {
		if(a[i] != b[i]) {
			std::cout << i << " " << i << "\n";
			return;
		}
	}
}

int main(){
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}