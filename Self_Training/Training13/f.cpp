#include <iostream>
#include <vector>
#include <cmath>

using i64 = long long;

int main() {
	int n, m;

	std::cin >> n >> m;

	std::vector<int> v;

	if(!n) {
		return std::cout << 0, 0;
	} else if(m == 10) {
		int cnt = 0;
		i64 ans = 0;
		while(n > 10) {
			int k = n % 10;

			if(k) {
				ans += pow(2, cnt);
			}
			cnt ++;
		}
	}

	while(n) {
		v.push_back(n % m);

		n /= m;
	}

	for(int i = (int)v.size() - 1; i >= 0; i --) {
		std::cout << v[i];
	}


}