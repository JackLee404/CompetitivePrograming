#include <bits/stdc++.h>

using namespace std;

int n, p, ans;
vector<int> v1;

int main() {
	cin >> n >> p;
	v1.resize(n);
	for (auto &x: v1) cin >> x;
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i ++) {
        auto l = upper_bound(v1.begin() + i + 1, v1.end(), abs(v1[i] - p)) - v1.end();
		auto r = lower_bound(v1.begin() + i + 1, v1.end(), p + v1[i]) - v1.end();
        ans += r - l;
	}
	cout << ans;
}