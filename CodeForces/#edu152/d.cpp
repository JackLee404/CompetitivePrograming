#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

struct node {
    int x, y;

    bool operator<(const node t) const {
        if (x == t.x) return y > t.y;
        return x < t.x;
    }
};

void solve() {
    int n = nxt<int>();

    std::vector<int> a(n + 1);

    for (int i = 1; i <= n; i ++) {
        a[i] = nxt<int>();
    }

    int ans = 0, l = 1;

    while (l <= n) {
        int r = l + 1;
        bool hasTwo = (a[l] == 2);
        bool hasMiddleZero = false;

        while (r <= n) {
            if (r - 1 > l && a[r - 1] == 0) {
                hasMiddleZero = true;
            }
            if (a[r] == 2) {
                hasTwo = true;
            }

            bool good = (not hasMiddleZero) and (hasTwo or a[l] != 0 or a[r] != 0);

            if (not good) {
                break;
            }
            
            r += 1;
        }

        l = r;
        ans += 1;
    }

    std::cout << ans << "\n";
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}