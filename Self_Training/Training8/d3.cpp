#include <iostream>
#include <map>

using i64 = long long;

const int N = 1e6 + 10;

std::map<int, int> mp;

int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

void solve(int x) {
    for(int i = 0; i < cnt; i ++) {
        int ct = 0;
        while(x % primes[i] == 0) {
            ct ++;
            x /= primes[i];
        }
        mp[primes[i]] += cnt;
    }
}

int main() {
    int n;
    
    std::cin >> n;

    get_primes(n);

    while(n) {
        solve(n);
        n --;
    }

    for(auto t: mp) {
        std::cout << t.first << " " << t.second << "\n";
    }
}