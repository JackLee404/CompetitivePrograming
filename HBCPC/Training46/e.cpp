#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int n, m, k;

    std::cin >> n >> m >> k;

    std::vector<std::vector<std::pair<int, int>>> a(n, std::vector<std::pair<int, int>>(m));

    for (int i = 0; i < n; i ++) {
    	for (int j = 0; j < m; j ++) {
    		std::cin >> a[i][j].first;
    		a[i][j].second = j + 1;
    	}

    	std::sort(a[i].begin(), a[i].end(), std::greater<std::pair<int, int>>());
    }


    int ed = (k % n) - 1;

    if (k % n == 0) ed = n - 1;

    std::vector<bool> st(m + 10000, false);

    std::vector<int> ans;

    while (k --) {
        int j = 0;

        while (st[a[ed][j].second]) {
            j ++; 
        }

        ans.push_back(a[ed][j].second);

        st[a[ed][j].second] = true;

        ed --;

        if (ed < 0) ed = n - 1;
    }

    std::sort(ans.begin(), ans.end());

    for (int i = 0; i < (int) ans.size(); i ++) {
        std::cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}