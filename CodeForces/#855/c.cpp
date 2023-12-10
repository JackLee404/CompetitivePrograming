#include <bits/stdc++.h>

const int mod = 1e9 + 7, N = 1e5 + 10;

using i64 = long long;

int primes[N], st[N], ct[N], cnt;

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
        ct[i] = cnt;
    }
}

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::map<int, std::vector<int>> mp;

	std::vector<int> v(n);

	for(auto &x: v) std::cin >> x;

	// std::sort(v.begin(), v.end());

	int mx, mi;

	int tot = 0;

	mx = mi = -1;
	
	for(int i = 0; i < n; i ++) {
		int k = v[i];
		for(int j = 0; primes[j] <= m; j ++) {
			if(v[i] % primes[j] == 0) {
				if(mi != -1) mi = std::min(v[i], mi);
				if(mx != -1) mx = std::max(mx, v[i]);
				if(mx == -1) mx = v[i];
				if(mi == -1) mi = v[i];
				// if(mp[primes[j]].empty()) tot ++, mp[primes[j]].push_back(v[i]);
				break;
			}
		}
	}

	if(tot != ct[m]) {
		std::cout << -1 << "\n";
		return;
	}

	sort()

	std::cout << mx << " " << mi << "\n"; 

	std::cout << mx - mi << "\n";
}

int main() {
	get_primes(100001);
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}