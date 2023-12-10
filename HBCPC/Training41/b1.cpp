#include <bits/stdc++.h>
#include <algorithm>

using i64 = long long;

const int N = 2e5 + 10;

/*
	a or b?

*/

int primes[N], cnt;

bool st[N];


void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1), v1, v2;

	for (int i = 1; i <= n; i ++) {
		if (i > 1 && !st[i]) v1.push_back(i);
		else v2.push_back(i);
	}

	int pos = n / 2, r = n + 1, l = 0;

	bool ok = true;

	// std::cout << v1.size() << "\n";

	for (int i = 0; i < v1.size(); i ++) {
		if (i % 2 == 0) {
			a[++ l] = v1[i];	
		} else {
			a[-- r] = v1[i];
		}
	}

	// a[(l + r) / 2] = 1;

	for (int i = l + 1, j = 0; i <= r - 1; i ++, j ++) {
		// if (v2[j] == 1 || i == (l + r) / 2) continue;
		a[i] = v2[j];
	}

	int pos2 = 0;

	for (int i = 1; i <= n; i ++) {
		if (a[i] == 1) pos2 = i;		
	}

	std::swap(a[pos2], a[(l + r) / 2]);



	for (int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}
}

int main() {
	get_primes(2e5 + 1);
	int _;

	std::cin >> _;	

	while (_ --) { solve(); }
}