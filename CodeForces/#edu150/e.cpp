#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

i64 lowbit(i64 x) {
	return x & -x;
}

/*
	区间内有多少个连续奇数
*/

void solve() {
	
	int n, q; std::cin >> n >> q;

	std::vector<int> a(n + 1), idx;

	int num = 0, cnt = 0;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];	

		if (a[i] % 2 != 0) {
			idx.push_back(i);
		}
	}

	while (q --) {
		int l, r, k; std::cin >> l >> r >> k;

		int pos = std::lower_bound(idx.begin(), idx.end(), l) - idx.begin();

		int val = 0;

		if (pos < idx.size()) {
			int num1 = 0, num2 = 0, seg = 0, sum = 0;


			for (int i = pos, j = 1; i < idx.size(); i ++, j ++) {
				if (idx[i] > r) break;	
				
				sum ++;

				if (j % 2 == 0) {
					cnt ++;	
					if (i != (int) idx.size() - 1) {
						num2 += a[i + 1] - a[i] - 1;

						if (a[i + 1] - a[i] - 1) seg ++;
					} 
				} 
			}

			num1 = sum / 2;	

			if (sum % 2 != 0) {
				puts("NO");
				continue;
			}

			puts(k <= num1 + num2 && k >= num1 + seg? "YES": "NO");
		} else puts(k <= (r - l + 1)? "YES": "NO");
	}
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}