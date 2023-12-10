#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

bool prime(int x) {
	if (x <= 1) return false;
	for (int i = 1; i <= x / i; i ++) if (x % i == 0) return false;
	return true;
}

void solve() {
    int n = nxt<int>();

    std::vector<int> a(n);

    i64 sum = 0;

    for (auto &x: a) {
    	std::cin >> x;

    	sum += x;
    }

    if (n == 1) {
    	puts(prime(a[0])? "Yes": "No");
    } else if (n == 2) {
    	if (sum % 2 == 0 && sum > 2) puts("Yes");
        else puts((prime(sum - 2))? "Yes": "No");
    } else {
    	puts(sum >= 2 * n? "Yes": "No");
    }
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}