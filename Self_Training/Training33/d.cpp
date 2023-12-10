#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using i64 = long long;

const int N = 2e5 + 10;

typedef std::pair<i64, i64> PII;

i64 w, h;

i64 n, A, B;

i64 p[N], q[N];

i64 a[N], b[N];

int main() {
	std::cin >> w >> h;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> p[i] >> q[i];

	std::cin >> A;

	for (int i = 1; i <= A; i ++) std::cin >> a[i];

	std::cin >> B;

	for (int i = 1; i <= B; i ++) std::cin >> b[i];

	a[A + 1] = w, b[B + 1] = h;

	std::map<PII, i64> mp;

	for (int i = 1; i <= n; i ++) {
		i64 X = *std::lower_bound(a + 1, a + A + 2, p[i]);
		i64 Y = *std::lower_bound(b + 1, b + B + 2, q[i]);
		mp[{X, Y}] ++;
	}

	i64 m = n, M = 0;

	for (auto p: mp) M = std::max(M, p.second);

	if (mp.size() == (A + 1) * (B + 1)) {
		for (auto p: mp) m = std::min(m, p.second);
	} else m = 0;

	std::cout << m << " " << M << "\n";
}