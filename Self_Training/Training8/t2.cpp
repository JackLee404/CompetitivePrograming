#include <iostream>

const int N = 1e5 + 10;

int a[N], stk[N], tt = 0;

int main() {
	int n;
	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		while(tt && a[stk[tt]] <= a[i]) tt --;

		if(tt) {
			std::cout << a[stk[tt]];
		} else {
			std::cout << "-1";
		}

		std::cout << " \n"[i == n - 1];

		stk[++ tt] = i;
	}
}