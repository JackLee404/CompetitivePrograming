#include <iostream>

using i64 = long long;

const int N = 1e6 + 10;

int stk[N], a[N], tt;

int main() {
	int n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		while(tt && stk[tt] >= a[i]) tt --;
		
		std::cout << ((!tt || stk[1] >= a[i])?-1:stk[tt]) << " \n"[i == n];
		
		stk[++ tt] = a[i];
	}
}