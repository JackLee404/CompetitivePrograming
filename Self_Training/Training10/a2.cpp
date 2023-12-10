#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1);

	int pos, neg;

	pos = neg = 0;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		a[i] -= a[i - 1];
		if(i>1) {
			pos += (a[i]>0);
			neg += (a[i]<0);
		}
	}

	std::cout << abs(pos - neg) + std::min(pos, neg) << "\n";
	std::cout << abs(pos - neg) + 1;
}