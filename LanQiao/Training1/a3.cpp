#include <iostream>


using i64 = long long;

const int N = 100;

int a[N];

int main() {
	int n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	int l = 1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(a[mid] >= 10) r = mid;
		else l = mid + 1;
	}

	std::cout << l << " " << r << "\n"
}