#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define f first
#define s second
using namespace std;

void solve() {
	int n, k;
	long long tag = 0;
	cin >> n >> k, tag = 0;
	vector<pair<int, int>> v(n);
	for (auto& x: v) {
		cin >> x.f;
	}
	for (auto& x: v) {
		cin >> x.s;
	}
	sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
		return a.s < b.s;
	});
	int k1 = 0;
	for (auto& x: v) {

		if (x.f + tag <= 0) continue;

		if (k1) k -= x.s;
		else k1 = 1;
		
		if (k > 0) {
			tag -= k;
			while (x.f + tag > 0) {
				k -= x.s;
				if (k < 0)
					break;
				tag -= k;
			}
		}

		if (x.f + tag > 0) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	int _;
	cin >> _;
	while (_ --) {
		solve();
	}
}