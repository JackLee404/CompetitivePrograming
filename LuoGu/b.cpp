#include <bits/stdc++.h>

using i64 = long long;

const int mod = 998244353;

const int N = 1e6 + 10;

template <typename T>
inline T nxt() {
    T x;
    std::cin >> x;
    return x;
}

int row[N], col[N];

void solve() {
    int n, m, q; std::cin >> n >> m >> q;

    int coln = 0, rown = 0, offcol = 0, offrow = 0;

    i64 ans = 0;

    std::vector<std::tuple<std::string, int, std::string>> v1(q);

    for (auto &[a, b, c]: v1) std::cin >> a >> b >> c;

    std::reverse(v1.begin(), v1.end());

    for (auto &[a, num, op]: v1) {
        if (a == "row") {
            if (op == "on") {
                if (!row[num]) {
                    rown ++;
                    ans += m - coln - offcol;
                    row[num] = 1;
                }
            } else {
                if (!row[num]) {
                    offrow ++;
                    row[num] = 1;
                }
            }
        } else {
            if (op == "on") {
                if (!col[num]) {
                    coln ++;
                    ans += n - coln - offrow;
                    col[num] = 1;
                }
            } else {
                if (!col[num][0]) {
                    offcol ++;
                    col[num] = 1;
                }
            }
        }
    }

    std::cout << ans;
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}