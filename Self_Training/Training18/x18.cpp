#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using i64 = long long;

const int N = 2e5 + 10;

i64 a[N], tr[N];
int n, ltl[N], ltr[N];

void add(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int ask(int x) {
	i64 res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		ltl[i] += ask(a[i]);
		add(a[i], 1);	
	}

	memset(tr, 0, sizeof tr);

	for (int i = n; i >= 1; i --) {
		ltr[i] += ask(a[i]);
		add(a[i], 1);
	}

	i64 ans1 = 0, ans2 = 0;

	for (int i = 1; i <= n; i ++) {
		ans1 += (i64) ltl[i] * ltr[i];
		ans2 += (i64) (i - 1 - ltl[i]) * (n - i - ltr[i]);
	}

	std::cout << ans2 << " " << ans1;
}