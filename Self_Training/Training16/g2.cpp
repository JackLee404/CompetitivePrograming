#include <iostream>
#include <cmath>
#include <vector>
#define act(x) sqrt(x / 2 + 1)
using i64 = long long;

const int N = 2e5 + 10;

i64 a[N], ans = 0;

std::vector<i64> g[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;

    std::cin >> n;

    for (int i = 1; i <= n; i++) std::cin >> a[i];

    for (int i = 1; i <= n; i++) {
        while (a[i] > 1) {
            bool ok = false;
            for (i64 t: g[i - 1]) {
                if (t == a[i]) {
                    ok = true;
                    break;
                }
            } 
            if (!ok) ans ++;
            g[i].push_back(a[i]);
            a[i] = act(a[i]); 
        }
    }

    std::cout << ans;
}
