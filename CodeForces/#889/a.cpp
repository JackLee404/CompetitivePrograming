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

   std::vector<int> a(n);

   int cnt = 0;

   for (int i = 0; i < n; i ++) {
   		std::cin >> a[i];

   		cnt += a[i] == i + 1;
   }

   std::cout << (int) std::ceil(cnt / 2.0) << "\n";
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}