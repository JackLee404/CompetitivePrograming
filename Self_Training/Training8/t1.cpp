#include <iostream>
#define rep(i, j, k) for(int i = j; i <= k; i ++)

const int N = 1e6 + 10;

int q[N], hh = 0, tt = -1;

int a[N];

int main() {
	int n, k;
	std::cin >> n >> k;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	for(int i = 1; i <= n; i ++) {
		if(hh <= tt && q[hh] < i - k + 1) hh ++;

		while(hh <= tt && a[q[tt]] >= a[i]) tt --;

		q[++ tt] = i;

		std::cout << a[q[hh]] << " \n"[i == n];
	}

	hh = 0, tt = -1;

	for(int i = 1; i <= n; i ++) {
		if(hh <= tt && q[hh] < i - k + 1) hh ++;

		while(hh <= tt && a[q[tt]] <= a[i]) tt --;

		q[++ tt] = i;

		std::cout << a[q[hh]] << " \n"[i == n];
	}
}