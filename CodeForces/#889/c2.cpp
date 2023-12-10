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

   std::vector<int> a(n + 1);

   int num_neg = 0, num_pos = 0, mxn = 0, mxp = 0;

   auto op = [&](int ix, int iy) {
      a[ix] += a[iy];
   };

   for (int i = 1; i <= n; i ++) {
      a[i] = nxt<int>();

      num_neg += a[i] < 0;
      num_pos += a[i] > 0;

      if (a[i] < a[mxn]) mxn = i;
      if (a[i] > a[mxp]) mxp = i;
   }

   if (!num_neg && !num_pos) {
      return puts("0"), void(0);
   }

   std::vector<std::pair<int, int>> ans;


   if (num_neg && num_pos) {

      int cp = 0;
      {
         int t = a[mxp];
         while (t < -a[mxn]) {
            t += t;
            cp ++;
         }
      }


      int cn = 0;
      {
         int t = a[mxn];
         while (t > -a[mxp]) {
            t += t;
            cn ++;
         }
      }

      if (cp + num_neg < cn + num_pos) {
         while (cp --) ans.push_back({mxp, mxp});
         for (int i = 1; i <= n; i ++) {
            if (a[i] < 0) ans.push_back({i, mxp});
         }
         for (int i = 2; i <= n; i ++) {
            ans.push_back({i, i - 1});
         }
      } else {
         while (cn --) ans.push_back({mxn, mxn});
         for (int i = 1; i <= n; i ++) {
            if (a[i] > 0) ans.push_back({i, mxn});
         }
         for (int i = n - 1; i >= 1; i --) {
            ans.push_back({i, i + 1});
         }
      }


   } else {
      if (num_pos)
         for (int i = 2; i <= n; i ++) ans.push_back({i, i - 1});
      else
         for (int i = n - 1; i >= 1; i --) ans.push_back({i, i + 1});
   }

   std::cout << ans.size() << "\n";

   for (auto &[f, s]: ans) {
      std::cout << f << " " << s << "\n";
   }
}

int main() {
   int _ = nxt<int>();
   while (_ --) { solve(); }
}