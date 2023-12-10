#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n;

	std::cin >> n;

	std::string a;

	std::cin >> a;

	int ans = 0;

	for(int i = 0, j = 0; i < n; i ++) {
		j = i;
		
		while(j < n && a[j] == 'x' && a[j] == a[j - 1]) j ++;

		if(j - i + 1 != 1) {
			int k = j - i + 1;

			if(k >= 3) {
				ans += k - 2;
			}
			
			i = j - 1;
		}
	}

	std::cout << ans;
}