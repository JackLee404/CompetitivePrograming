#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

/*
	prefix[i] 
*/

void solve() {
    int n;

    std::cin >> n;

    i64 delta = 0, ans = 0;
    i64 sum = 0, mx = 0;

    for (int i = 0; i < n; i ++) {
    	int x; std::cin >> x;

    	sum += x;

    	mx = std::max(mx, sum);

    	if (sum - mx < delta) {
    		delta = sum - mx;
    		ans = mx;
    	}
    }

    std::cout << ans << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}