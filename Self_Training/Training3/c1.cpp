#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5, M = 1e6 + 10;

// lnn 素数 1~1e9 --> lnn

int primes[M], cnt;     // primes[]存储所有素数
bool st[M];         // st[x]存储x是否被筛掉

void get_primes() {
    for (int i = 2; i <= N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= N / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


void solve() {
	int n;
	std::unordered_map<int, bool> mp;

	std::cin >> n;

	bool ok = false;
	for(int i = 0; i < n; i ++) {
		int t;
		std::cin >> t;

		if(ok) continue;

		for(int j = 0; primes[j] <= t / primes[j]; j ++) {
			if(t % primes[j] == 0) {	

				while(t > 0 && t % primes[j] == 0) {
					t /= primes[j];
				}

				if(mp[primes[j]]) ok = true;
				else mp[primes[j]] = true;

			}
		}

		if(t > 1) {
			if(mp[t]) ok = true;
			else mp[t] = true;	
		}
	}
	std::cout << (ok?"YES\n":"NO\n");
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	get_primes();
	int _;
	std::cin>>_;
	while(_ --) {
		solve();
	}
}