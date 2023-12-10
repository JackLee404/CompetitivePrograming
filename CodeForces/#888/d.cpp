#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
	int n = nxt<int>();

	std::vector<i64> a(n + 1), extra;

	std::vector<bool> used(n + 1);

	for (int i = 1; i < n; i ++) a[i] = nxt<i64>();

	for (int i = 1; i < n; i ++) {
		i64 d = a[i] - a[i - 1];

		if (d <= n && d >= 1 && !used[d]) {
			used[d] = 1;	
		} else {
			extra.push_back(d);
		}
	}

	if (extra.empty()) {
		puts("YES");
		return;
	}

	if (extra.size() != 1) {
		puts("NO");
		return;
	}

	std::vector<i64> left;

	for (int i = 1; i <= n; i ++) {
		if (!used[i]) {
			left.push_back(i);
		}
	}

	if (left.size() == 2 && extra[0] == left[0] + left[1]) {
		puts("YES");
	} else {
		puts("NO");
	}
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}