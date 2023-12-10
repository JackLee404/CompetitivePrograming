#include <iostream>

using i64 = long long;

int main() {
	int n;

	std::cin >> n;

	n ++;

	for(int i = n; ; i ++) {
		int t = i;

		bool ok = true;

		while(t > 0) {
			if(t % 16 <= 9) ok = false;
			t /= 16;
		}

		if(ok) {
			std::cout << i << "\n";
			break;
		}
	}
}