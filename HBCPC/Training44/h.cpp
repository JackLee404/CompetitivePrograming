#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10;

const i64 INF = 0x3f3f3f3f3f3f3f3f;

i64 a[N], b[N];

struct node {
	i64 l, r;
	int type;

	node (i64 _l, i64 _r) {
		l = std::min(_l, _r);
		r = std::max(_l, _r);
		type = _l > _r;
	}

	bool operator<(const node &b) const {
		return r < b.r;
	}
};

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	for (int i = 1; i <= n; i ++) std::cin >> b[i];

	std::vector<node> v1;

	i64 sum = 0;

	for (int i = 1; i <= n; i ++) {
		sum += std::abs(a[i] - b[i]);	
		v1.emplace_back(a[i], b[i]);
	}

	std::sort(v1.begin(), v1.end());

	i64 overlap = 0, l[2] = {INF, INF};

	for (int i = n - 1; i >= 0; i --) {
		int difType = v1[i].type ^ 1;
		
		if (l[difType] < v1[i].r)
			overlap = std::max(overlap, v1[i].r - std::max(v1[i].l, l[difType]));

		l[v1[i].type] = std::min(l[v1[i].type], v1[i].l);	
	}

	std::cout << sum - 2 * overlap;
}