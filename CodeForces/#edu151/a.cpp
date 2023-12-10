#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void out(int n, int x) {
   	std::cout << "YES\n" << n << "\n";
	for (int i = 1; i <= n; i ++) {
		std::cout << x << " \n"[i == n];
	}
}

void solve() {
    int n, k, x;

    std::cin >> n >> k >> x;

    if (x != 1) {
    	out(n, 1);
    } else {
    	if (k == 1) puts("NO");
    	else if (k == 2) {
    		if (n % 2 == 0) out(n / 2, 2);
    		else puts("NO");
    	} else {
    		if (n % 2 == 0) out(n / 2, 2);
    		else if (n < 3) puts("NO");
    		else {
    			std::cout << "YES\n" << (n - 3) / 2 + 1 << "\n";
    			for (int i = 1; i <= (n - 3) / 2; i ++) {
    				std::cout << 2 << " ";
    			}
    			std::cout << 3 << "\n";
    		}
    	}
    }
}

int main() {
    int _ = nxt<int>();
    while (_ --) { solve(); }
}