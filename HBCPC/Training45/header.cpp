#include <iostream>
#include <cstdint>

using i64 = long long;

using u128 = __int128;

struct fastmod {
    using u64 = uint64_t;
    using u128 = __int128;
    int f, l; u64 m, d;
    fastmod(u64 d): d(d) {
        l = 64 - __builtin_clzll(d - 1);
        const u128 one = 1;
        u128 M = ((one << (64 + l)) + (one << l)) / d;
        if(M < (one << 64)) f = 1, m = M;
        else f = 0, m = M - (one << 64);
    }
    friend u64 operator/(u64 n, const fastmod &m) { // get n / d
        if (m.f) return u128(n) * m.m >> 64 >> m.l;
        else {
            u64 t = u128(n) * m.m >> 64;
            return (((n - t) >> 1) + t) >> (m.l - 1);
        }
    }
    friend u64 operator%(u64 n, const fastmod &m) { // get n % d
        return n - n / m * m.d;
    }
};