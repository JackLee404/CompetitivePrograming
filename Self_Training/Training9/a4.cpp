#include <iostream>

using i64 = long long;

const int N = 1e3 + 10;

int a[N], f[N], stk[N], n;

int ans1, ans2;

int main() {
	int x;

	while(std::cin >> x) {
		a[++ n] = x;
	}

	for(int i = 1; i <= n; i ++) {
		f[i] = 1;

		for(int j = 1; j < i; j ++) {
		    if(a[j] > a[i])
			    f[i] = std::max(f[i], f[j] + 1);
		}

		ans1 = std::max(ans1, f[i]);
	}

	std::cout << ans1 << "\n";

	stk[0] = 2e9;
	int len = 0;

	for(int i = 1; i <= n; i ++) {
		int l = 0, r = len;
		while(l < r) {
			int mid = l + r >> 1;
			if(stk[mid] > x) r = mid;
			else l = mid + 1;
		}
		if(l != r) {
			stk[len + 1] = a[i];
			len ++;	
		}else {
			stk[l] = a[i];
			len = std::max(len, l);
		}
	}

	std::cout << len << "\n";
}