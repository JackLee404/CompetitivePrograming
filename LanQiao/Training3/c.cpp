#include <iostream>

using i64 = long long;

const int N = 1e6 + 10, M = 2e6;

int q[M], hh, tt = -1;

int a[N];

int main() {
	int n, k;

	std::cin >> n >> k;


	for(int i = 1; i <= n; i ++) {

		std::cin >> a[i];

		while(hh <= tt && q[hh] < i - k + 1) hh ++;

		while(hh <= tt && a[q[tt]] >= a[i]) tt --;

		q[++ tt] = i;

		if(i >= k)
			std::cout << a[q[hh]] << " \n"[i == n];
	}

	hh = 0, tt = -1;

	for(int i = 1; i <= n; i ++) {

		// std::cin >> a[i];

		while(hh <= tt && q[hh] < i - k + 1) hh ++;

		while(hh <= tt && a[q[tt]] <= a[i]) tt --;

		q[++ tt] = i;

		if(i >= k)
			std::cout << a[q[hh]] << " \n"[i == n];
	}
}