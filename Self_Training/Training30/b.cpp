#include <bits/stdc++.h>
#define ff first
#define ss second

using i64 = long long;

const int N = 1e5 + 10;

const double EPS = 1e-6;

typedef std::pair<i64, i64> PII;

struct node {
	int id;
	double pos, v, ipos;

	bool operator<(const node t) const {
		if (pos == t.pos) {
			return id > t.id;
		}
		return pos < t.pos;
	}
};

int n, k;

node a[N];

/*
	check O(nlogn)
	binary-search O(logn) calculate LIS

	--> nlog^2n
*/

bool check(double time) {
	static int stk[N];

	int len = 0;
    
	for (int i = 1; i <= n; i ++) {
		a[i].pos = a[i].ipos + time * a[i].v;
	}

	std::sort(a + 1, a + 1 + n);

	stk[0] = -1e9;

	for (int i = 1; i <= n; i ++) {
		int l = 0, r = len;

		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (stk[mid] < a[i].id) l = mid;
			else r = mid - 1;
		}

		stk[l + 1] = a[i].id;

		len = std::max(len, l + 1);
	}
    
	return n - len <= k;
}

int main() {
	std::cin >> n >> k;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i].pos >> a[i].v;

		a[i].ipos = a[i].pos;
	}

	std::sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i ++) {
		a[i].id = i;
	}

	double l = 0, r = 1e10 + 1;

	int cnt = 1;

	while (r - l > EPS) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}

	if (r == 1e10 + 1) {
		std::cout << -1;
	} else {
		printf("%.4lf", l);
	}
}