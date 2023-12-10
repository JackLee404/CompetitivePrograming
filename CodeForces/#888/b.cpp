#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int n = nxt<int>();

    std::unordered_map<int, int> idx;

    std::vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i ++) {
    	b[i] = a[i] = nxt<int>();
    	idx[b[i]] = i;
    }

   	std::sort(a.begin() + 1, a.end());

   	bool ok = true;

   	for (int i = 1; i <= n; i ++) {
   		if (a[i] % 2 != b[i] % 2) {
   			ok = false;
   		}
   	}

   	puts(ok? "YES": "NO");
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}