#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> v(n), v2(n);

	for(int i = 0; i < n; i ++) {
		std::cin >> v[i];
		v2[i] = v[i];
	}

	std::sort(v2.begin(), v2.end());

	int pos = -1;

	for(int i = 0; i < n; i ++) {
		if(v2[i] == 1) {
			pos = i;
			break;
		}
	}

	if(pos == -1) {
		puts("0");
		return;
	}

	int cnt1, cnt2;
	cnt1 = cnt2 = 0;

	for(int i = 0; i < n; i ++) {
		if(i < pos && v[i] == 1) cnt1++;
		else if(i >= pos && v[i] == 0) cnt2 ++;
	}

	std::cout << cnt1 << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}