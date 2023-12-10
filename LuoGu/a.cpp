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

bool row[N], col[N];


void solve() {
    int n, m, q; std::cin >> n >> m >> q;

    int coln = 0, rown = 0, offcol = 0, offrow = 0;

    i64 ans = 0;

    std::vector<std::tuple<std::string, int, std::string>> v1(q);

    for (auto &[a, b, c]: v1) std::cin >> a >> b >> c;

    std::reverse(v1.begin(), v1.end());

    for (auto &[a, num, op]: v1) {
        if (a == "row" && !row[num]) {
            row[num] = 1;

            if (op == "on") {
                ans += m - coln;
                rown ++;
            } else {
                rown ++;
            }
        }
        if (a == "column" && !col[num]) {
            col[num] = 1;

            if (op == "on") {
                ans += n - rown;
                coln ++;
            } else {
                coln ++;
            }
        }
    }

    std::cout << ans;
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}