#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 100;

int n, m, ans1, ans2;

int a[N];

std::vector<int> a1, b1;

void out(std::vector<int> &a1) {
	if (a1.empty()) return;
	ans1 ++;
//	for (auto t: a1) {
//		std::cout << t << " ";
//	}
//	puts("");
	ans2 = std::max(ans2, (int)a1.size());
	a1.clear();
}

int main() {
	std::cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	
	a1.push_back(a[1]);
	
	for (int i = 2; i <= n; i ++) {
		if (a[i] >= a1.back()) {
			if (b1.empty() || a[i] > b1.back()) {
				b1.push_back(a[i]);
			} else {
				out(a1);
				while (b1.size() && b1.back() > a[i]) {
					a1.push_back(b1.back());
					b1.pop_back();
				}
				a1.push_back(a[i]);
			}
		} else a1.push_back(a[i]);
	}
	
	out(a1);
	out(b1);
	
	std::cout << ans1 << " " << ans2;
}