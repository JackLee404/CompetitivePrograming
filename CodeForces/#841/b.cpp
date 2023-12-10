#include <bits/stdc++.h>
typedef __int128 i128;
using namespace std;

const long long mod = 1e9 + 7;

void solve() {
	int n; cin >> n;
	i128 x = n, ans = 0;
	ans = (x * (x + 1) * (2 * x + 1) / 3) - 1 - ((2 + x) * (x - 1)) / 2;
	ans %= mod;
	long long res = ans;
	cout << (res * 2022) % mod << "\n";
}

int main(){
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}