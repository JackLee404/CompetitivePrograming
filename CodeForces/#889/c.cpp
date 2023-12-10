#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

 
std::vector<std::pair<int, int>> v1;

void solve() {
   v1.clear();
   
   int n = nxt<int>();

   std::vector<int> a(n);

   int mx = 0;

   for (int i = 0; i < n; i ++) {
      a[i] = nxt<int>();

      if (std::abs(a[i]) > std::abs(a[mx])) {
         mx = i;
      }
   }

   std::vector<std::pair<int, int>> res;

   for (int i = 1; i <= n; i ++) {
      res.push_back({i, mx + 1});
   }

   if (a[mx] > 0) {
      for (int i = 2; i <= n; i ++) {
         res.push_back({i, i - 1});
      }
   } else if (a[mx] < 0) {
      for (int i = n - 1; i >= 1; i --) {
         res.push_back({i, i + 1});
      }
   }

   std::cout << res.size() << "\n";

   for (auto &[f, s]: res) {
      std::cout << f << " " << s << "\n";
   }
}

int main() {
   int _ = nxt<int>();
   while (_ --) { solve(); }
}