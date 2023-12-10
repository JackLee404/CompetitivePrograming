#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

long long binaryToDecimal(const std::string& binaryString) {
    unsigned long long tempValue = std::bitset<64>(binaryString).to_ullong();
    long long decimalValue = static_cast<long long>(tempValue);
    return decimalValue;
}

bool prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i ++) {
		if (x % i == 0) return false;
	}
	return true;
}

void solve() {
	int n = nxt<int>();

	std::vector<int> a(n + 1);

	int cnt[4];

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		if (prime(a[i])) {
			if (a[i] % 2 == 0) cnt[0] ++;
			else cnt[1] ++;
		} else {
			cnt[2] += (a[i] % 2 == 0);
			cnt[3] += (a[i] % 2 != 0);
		}
	}

	bool cond1 = (cnt[2] && cnt[2] % 2 && !cnt[0]), cond2 = (cnt[3] && cnt[3] % 2 && !cnt[1]);

	// std::cout << cond1 << " " << cond2 << "\n";

	if (cond1 || cond2) {
		puts("No");
	} else {
		puts("Yes");
	}
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}