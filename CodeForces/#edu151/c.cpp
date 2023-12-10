#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
	std::string s, l, r;

	int m;

	std::cin >> s >> m >> l >> r;

	std::vector<std::vector<int>> v1(10);

	for (int i = 0; i < s.size(); i ++) {
		int x = s[i] - '0';

		v1[x].push_back(i);
	}

	int idx = -1;

	bool ok = false;

	for (int i = 0; i < m; i ++) {
		int mx = -1;

		for (int j = l[i]; j <= r[i]; j ++) {
			int z = j - '0';	

			if (v1[z].empty()) {
				ok = true;
				break;
			}

			int l = 0, r = (int) v1[z].size() - 1;

			while (l < r) {
				int mid = l + r >> 1;

				if (v1[z][mid] > idx) r = mid;
				else l = mid + 1;
			}

			if (v1[z][l] <= idx) {
				ok = true;
			}

			if (v1[z][l] > mx) {
				mx = v1[z][l];
			}

			// std::cout << i << " " << v1[z][l] << "\n";
		}

		idx = mx;

		if (ok) {
			break;
		}

		// std::cout << "idx:" << idx << "\n";
	}

	puts(ok? "YES": "NO");
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}