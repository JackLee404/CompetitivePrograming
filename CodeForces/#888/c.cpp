#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int n, k;

    std::cin >> n >> k;

    std::vector<int> a(n + 1);

    int cnt1 = 0;

    for (int i = 1; i <= n; i ++) {
        a[i] = nxt<int>();

        cnt1 += a[i] == a[1];
    }

    if (a[1] == a[n] && cnt1 >= k) {
        puts("YES");
    } else {
        int cnt2 = 0;
        for (int i = n; i >= 1; i --) {
            cnt2 += a[i] == a[n];

            cnt1 -= a[i] == a[1];

            if (cnt2 >= k) break;
        }

        puts((cnt1 >= k && cnt2 >= k)? "YES": "NO");
    }
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}