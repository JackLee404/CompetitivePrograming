#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
    T x;
    std::cin >> x;
    return x;
}

long long binaryToDecimal(const std::string& binaryString) {
    unsigned long long tempValue = std::bitset<64>(binaryString).to_ullong();
    long long decimalValue = static_cast<long long>(tempValue);
    return decimalValue;
}

int n, m;

std::vector<std::vector<int>> G;

std::vector<int> en;

std::vector<int> res;

void bfs() {
    std::queue<int> q1;

    for (int i = 1; i <= n; i ++) {
        if (!en[i]) q1.push(i);
    }

    while (q1.size()) {
        int u = q1.front(); q1.pop();

        res.push_back(u);

        for (auto v: G[u]) {
            if (-- en[v] == 0) {
                q1.push(v);
            }
        }
    }
}

void solve() {
    n = nxt<int>(), m = nxt<int>();

    G.resize(n + 1), en.resize(n + 1);

    for (int i = 1; i <= m; i ++) {
        int a = nxt<int>(), b = nxt<int>();
        G[a].push_back(b), en[b] ++;
    }

    for (int i = 1; i <= n; i ++) std::sort(G[i].begin(), G[i].end());

    bfs();

    if (res.size() != n) {
        std::cout << 2 << "\n";
    } else std::cout << 1 << "\n";


    for (int i = 0; i < n; i ++) {
        std::cout << res[i] << " \n"[i == n - 1];
    }

    if (res.size() != n) {
        for (int i = 1; i <= n; i ++) {
            std::cout << res[i] << " \n"[i == n];
        }
    }
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}