#include <bits/stdc++.h>
#define PII std::pair<int, int>
using i64 = long long;

const int N = 1e5 + 10;

int n;

int stk[N], a[N], hh = 0, tt = -1;

std::priority_queue<PII> q1;

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		while (hh <= tt && a[stk[tt]] < a[i]) tt --;

		if (hh <= tt)
			std::cout << stk[tt] - 1 << " \n"[i == n];
		else std::cout << -1 << " \n"[i == n];

		stk[++ tt] = i;
	}
}