#include <iostream>

using i64 = long long;

const int N = 1e4 + 10;

int q[N], a[N], hh, tt = -1;

int arr[N];

int main() {
	int n, k;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	std::cin >> k;

	for(int i = 1; i <= n; i ++) {
		while(hh <= tt && q[hh] < i - k) hh ++;

		while(hh <= tt && a[i] <= a[q[tt]]) tt --;

		q[++ tt] = i;

		arr[i] = a[q[hh]];

		// std::cout << arr[i] << "\n";
	}

	for(int i = 1; i <= n; i ++) {
		std::cout << std::min(arr[i], arr[std::min(n, i + k)]) << " \n"[i == n];
	}
}