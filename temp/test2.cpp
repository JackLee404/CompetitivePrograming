#include <bits/stdc++.h>

using namespace std;

int n, p, ans;
vector<int> v1;

int main() {
	cin >> n >> p;
	v1.resize(n);
	for (auto &x: v1) cin >> x;
	auto t = lower_bound(v1.begin(), v1.end(), 2);
	cout << *t;
}