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
    int n, k;

    std::cin >> n >> k;

    std::vector<std::pair<int, int>> a(n);

    int cnt = 0;

    for (auto &[f, s]: a) {
        std::cin >> f;

        f %= k;

        if (!f) f = k;

        s = ++ cnt;
    }

    std::stable_sort(a.begin(), a.end(), [](std::pair<int, int> t1, std::pair<int, int> t2) {
        if (t1.first == t2.first) {
           return t1.second < t2.second;
        } else return t1 > t2;
    });

    for (int i = 0; i < n; i ++) {
        std::cout << a[i].second << " \n"[i == n - 1];
    }
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}