#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

void solve() {
    int n = nxt<int>();

    std::vector<std::vector<int>> a(n, std::vector<int>(n));

    for (int i = 0; i < n; i ++) {
    	for (int j = 0; j < n; j ++) {
    		char x = nxt<char>();
    		a[i][j] = (x == '1');
    	}
    }

    bool ok = true;

    int cnt1 = 0, cnt2 = 1;


    for (int i = 1; i < n; i ++) {
    	bool cond1 = true, cond2 = true;

    	for (int j = 0; j < n; j ++) {
    		if (a[i][j] != a[0][j]) cond1 = false;
    	}	

    	for (int j = 0; j < n; j ++) {
    		if (a[i][j] != !a[0][j]) cond2 = false;
    	}

    	if (cond1) cnt2 ++;
    	if (cond2) cnt1 ++;

    	ok &= (cond1 | cond2);
    }

	if (ok) {
		int num1 = 0, num2 = 0;

		for (int i = 0; i < n; i ++) num1 += a[0][i], num2 += !a[0][i];

		int t = std::min(num1, num2);

		std::cout << std::min(t + cnt1, t + cnt2);
	} else {
		std::cout << -1;
	}
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}