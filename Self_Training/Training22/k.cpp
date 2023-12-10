#include <bits/stdc++.h>
#define PII std::pair<int, int>
using i64 = long long;

const int N = 1e5 + 10;

int check(std::string a, std::string b) {
	int i = (int) a.size() - 1;
	int j = (int) b.size() - 1;

	int ans = 0;

	for (; i >= 0 && j >= 0; i --, j --) {
		if (a[i] != b[j]) break;
		ans ++;
	}

	return ans;
}

int main() {
	std::string a, b, c;

	std::cin >> a >> b >> c;

	std::cout << check(a, b) << " " << check(a, c);
}