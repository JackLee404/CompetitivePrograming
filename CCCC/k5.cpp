#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int n, k;

std::vector<int> a[N], d[N];

int main() {
	std::cin >> k;
	
	int win;
	
	for (int i = 1; i <= k; i ++) {
		a[i].resize((int) pow(2, k - i));
		
		for (auto x: a[i]) {
			std::cin >> x;
		}
	}
	
    std::cout << "No Solution";

}