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
    int n, m;

    std::cin >> n >> m;

    std::vector<int> lf(n), rg(n);

    std::string t = nxt<std::string>();

    lf[0] = -1;

    for (int i = 0; i < n; i ++) {
        if (i > 0) lf[i] = lf[i - 1];
        if (t[i] == '0') lf[i] = i;
    }

    rg[n - 1] = n;

    for (int i = n - 1; i >= 0; i --) {
        if (i + 1 < n) rg[i] = rg[i + 1];
        if (t[i] == '1') rg[i] = i;
    }

    std::set<std::pair<int, int>> st;

    for (int i = 0; i < m; i ++) {
        int l, r;

        std::cin >> l >> r;

        int ll = rg[l - 1], rr = lf[r - 1];

        if (ll > rr) {
            st.insert({-1, -1});
        } else {
            st.insert({ll, rr});
        }
    }

    std::cout << st.size() << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}