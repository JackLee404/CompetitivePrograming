#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int q; std::cin >> q;

    std::string ans;

    std::vector<int> v1, v2;

    while (q --) {
        int x; std::cin >> x;

        if (ans.empty()) {
            ans.push_back('1');
            v1.push_back(x);
        } else {
            if (v2.empty() && x >= v1.back()) {
                v1.push_back(x);
                ans.push_back('1');
            } else if ((v2.empty() && x <= v1[0]) || (v2.size() && x >= v2.back() && x <= v1[0])) {
                v2.push_back(x);
                ans.push_back('1');
            } else ans.push_back('0');
        }
    }

    std::cout << ans << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}