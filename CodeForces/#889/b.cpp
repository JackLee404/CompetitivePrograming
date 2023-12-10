#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
   i64 n = nxt<i64>();

   i64 cnt = 0;

   for (i64 i = 1; i <= n; i ++) {
      if (n % i == 0) {
         cnt ++;
      } else break;
   }

   std::cout << cnt << "\n";
}

int main() {
   // i64 t = 1;
   // for (i64 i = 1e4, j = 1e4;; i ++) {
   //    t *= i;

   //    std::cout << t << "\n";

   //    if (t >= 1e18) {
   //       std::cout << i - j + 1 << "\n";
   //       break;
   //    }
   // }
   int _ = nxt<int>();
   while (_ --) { solve(); }
}