#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10;

int main() {
	int _;
	cin >> _;
	int a[N];
	while (_ --) {
		LL res = 0;
		int n, maxi = 0;
		cin >> n;
		for (int i = 0; i < n; i ++) {
			int l, r;
			cin >> l >> r;
			int k1 = max(l, r), k2 = min(l, r);
			if (k1 > maxi) maxi = k1;
			res += k2;
		}
		cout << res * 2 + maxi * 2 << endl;
	}
}