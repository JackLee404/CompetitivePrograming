#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10, mod = 1e9 + 7;

int n, q;

i64 arr[N], sum[N], diff[N], tmp[N];

struct node {
	int l, r, w;
} tr[4 * N];



int main() {

	std::cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];

		sum[i] = sum[i - 1] + arr[i];
	}

	while(q --) {
		int op, a, b, c;

		std::cin >> op >> a >> b;

		if(!op) {
			std::cin >> c;

			diff[a] += c, diff[b + 1] -= c;
			
		} else {
			memcpy(tmp, diff, sizeof diff);

			for (int i = 1; i <= n; i ++) {
				tmp[i] += tmp[i - 1];

				sum[i] = tmp[i] + sum[i - 1] + arr[i];

				// std::cout << tmp[i] << " \n"[i == n];
			}

			std::cout << (sum[b] - sum[a - 1]) << "\n";
		}
	}
}