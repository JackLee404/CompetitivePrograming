#include <bits/stdc++.h>

using i64 = long long;

int num[20];

bool check(int x) {
	if(!x) {
		if(!num[0]) return false;
		num[0] --;
	}

	while(x) {
		if(!num[x % 10]) return false;
		num[x % 10] --;
		x /= 10;
	}

	return true;
}

int main() {
	int m;

	std::cin >> m;

	for(int i = 0; i <= 9; i ++) {
		num[i] = m;
	}

	for(int i = 1; ; i ++) {
		if(!check(i)) {
			std::cout << i - 1;
			break;
		}
	}
}