#include <iostream>
#include <vector>
using i64 = long long;

int main() {
	int n, m, ans = 0;
	std::cin >> n >> m;


	std::vector<int> a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	for(int i = 1, j = 1; i <= n; i ++) {
		int pos = -1, cnt = 0;
		for(; j <= n && cnt < m; j ++) {
			if(!a[i]) cnt ++;
			else {
				if(a[])
			}
		}
	}
}