#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

const int N = 5e5 + 10;

int q[N], hh = 0, tt = -1;

void solve() {
    int n, k;

    std::cin >> n >> k;

    std::vector<int> a(n + 1), count(5, 0);

    auto check = [&]() {
    	for (int i = 1; i <= 4; i ++) {
    		if (i <= 3 && !count[i]) return false;
    		if (i == 4 && count[i] < k) return false;
    	}
    	return true;
    };

    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    int ans = n;

    for (int i = 1; i <= n; i ++) {
    	count[a[i]] ++;

    	while (hh <= tt && ((a[q[hh]] == 4 && count[4] > k) || (a[q[hh]] != 4 && count[a[q[hh]]] >= 2))) {
    		count[a[q[hh]]] --;
    		hh ++;	
    	}

    	q[++ tt] = i;

    	if (check()) {
    		ans = std::min(ans, tt - hh + 1);
    		// for (int i = hh; i <= tt; i ++) {
    		// 	std::cout << a[q[i]] << " \n"[i == tt];
    		// }
    	}
    }

    std::cout << ans << "\n";
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}