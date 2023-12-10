#include <iostream>
typedef long long bl;
using namespace std;

const int N = 600;

using i64 = long long;

int n, p;

i64 fast_pow(i64 a, i64 b, i64 p) {
    i64 ans = 1;
    while(b > 0) {
        if(b & 1) ans *= a % p;
        a *= a % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    // ios::sync_with_stdio(0);
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i ++) {
        std::cout << fast_pow(i, p - 2, p) << "\n";
    }
}