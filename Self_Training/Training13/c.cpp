#include <iostream>

using i64 = long long;

const int N = 1e4 + 10;

int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int memory_data[N];

int count(int x) {
	int cnt = 0;

	if(!x) return 6;

	while(x) {
		cnt += num[x % 10];
		x /= 10;
	}

	return cnt;
}

int main() {
	int n, ans = 0;

	std::cin >> n;

	n -= 4;

	for(int i = 0; i <= 10000; i ++) {
		int cnt = count(i);

		if(cnt > n) continue;

		for(int j = i; j <= 10000; j ++) {
			if(cnt + count(j) + count(i + j) != n) continue;

			ans += (i == j?1:2);
		}
	}

	// std::cout << count(1) + count(1) + count(2) + 4 << "\n";
	std::cout << ans;
}