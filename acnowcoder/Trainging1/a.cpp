#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10;

int a[N], mx, t, m, b[N];

long long frac(long long x) {
	if (a[x] == -1) {
		a[x] = (x == 1? x: x * frac(x - 1));
		return a[x];
	}
	else {
		return a[x];
	}
}

int count(int m) {
	int num = 1;
	while (frac(num) < m) {
		cout << num << " " << frac(num) << endl;
		num ++;	
	}
	return num;
}

void solve() {
	for(int i = 1; i <= frac(mx - 1); i ++) {
		if (i == 1) b[i] = i % m;
		else b[i] = ((i % m) * b[i - 1]) % m;
	}
}


int main() {
	memset(a, -1, sizeof a);
	cin >> t >> m;
	mx = count(m);
	cout << mx << endl;
	solve();

	while (t --) {
		int n;
		cin >> n;
		if (n >= mx) {
			cout << 0 << endl;
		} else {
			cout << b[frac(n)] << endl;
		}
	}
	// int n;
	// while (cin >> n) {
	// 	cout << frac(n) << endl;
	// }
}