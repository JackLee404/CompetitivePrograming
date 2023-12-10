#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
    T x;
    std::cin >> x;
    return x;
}

const int N = 3e3 + 10;

void solve() {
    std::ios::sync_with_stdio(false);
    
    int n;
    
    std::cin >> n;

    int ans = 0;
    
    std::vector<std::vector<int>> v1(n + 1);

    std::vector<int> left(n + 1), right(n + 1);

    std::vector<bool> st(n + 1);

    for (int i = 1; i <= n; i ++) {
        bool ok = false;
        for (int j = 1; j <= n; j ++) {
            int x;
            std::cin >> x;
            if (x) left[i] ++, right[i] ++;
        }
    }
    
    int n1 = 0, n2 = 0;
    
    for (int i = 1; i <= n; i ++) {
        if (left[i]) n1 ++;
        if (right[i]) n2 ++;
    }


    std::cout << n1 << "\n";
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}