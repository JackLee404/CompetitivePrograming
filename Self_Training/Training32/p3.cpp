#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10;

int n;

double q = 1.12842577148, t = 6.86766352642;

int main() {
   printf("%.2lf", t);

   double q2 = q;

   for (int i = 2; i <= 36; i ++) {
      printf(" %.2lf", t * q);

      q *= q2;
   }
}