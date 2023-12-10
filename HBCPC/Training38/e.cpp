#include <bits/stdc++.h>

int power(int a, int e) {
    if (e == 0) return 1;
    return e == 1 ? a : a * power(a, e-1);
}

void answer(int a, int b) {
    std::cout << a << " + " << b << " = " << a+b << std::endl;
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    using ll = long long;
    
    int t;
    std::cin >> t;
    while (t--) {

        int a, b, c;
        ll k;
        std::cin >> a >> b >> c >> k;
        
        bool good = false;
    
        for (int i = power(10, a-1); i < power(10, a); ++i) {
            int left = std::max(power(10, b-1), power(10, c-1) - i);
            int right = std::min(power(10, b)-1, power(10, c) - 1 - i);
            if (left > right) continue;
    
            int have = right - left + 1;
            if (k <= have) {
                answer(i, left + k - 1);
                good = true;
                break;
            }
    
            k -= have;
        }
    
        if (!good) std::cout << "-1" << std::endl;
    }

    return 0;
}