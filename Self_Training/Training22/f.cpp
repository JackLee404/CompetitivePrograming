#include <bits/stdc++.h>

using i64 = long long;

int cnt1[20], cnt2[20];

bool check(int a, int b) {
	if (!a && !b) return true;

	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);

	while (a) {
		cnt1[a % 10] ++;
		a /= 10;
	}

	while (b) {
		cnt2[b % 10] ++;
		b /= 10;
	}

	for (int i = 0; i <= 9; i ++) {
		if (cnt1[i] != cnt2[i]) return false;
	}
	return true;
}

int main() {
	int a, b;

	std::cin >> a >> b;

	std::cout << a <<  " " << b << "\n";

	if (a == b) {
		puts("Equal");
	} else if (check(a, b)) {
		puts("ALIEN");
	} else { 
		puts("Different");
	}
}