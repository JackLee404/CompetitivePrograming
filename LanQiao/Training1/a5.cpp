#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 2000003, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
	int k = (x % N + N) % N;

	while(h[k] != null && h[k] != x) {
		k ++;
		if(k == N) k = 0;
	}

	return k;
}

int main() {
	// for(int i = 2e6; ; i ++) {
	// 	bool ok = true;
	// 	for(int j = 2; j <= i / j; j ++) {
	// 		if(i % j == 0) {
	// 			ok = false;
	// 			break;
	// 		}
	// 	}
	// 	if(ok) {
	// 		std::cout << i << "\n";
	// 		break;
	// 	}
	// }

	memset(h, 0x3f, sizeof h);

	int n;

	std::cin >> n;


	while(n --) {
		std::string t;
		int x;

		std::cin >> t >> x;
		int k = find(x);

		if(t == "I") {
			h[k] = x;
		} else {
			std::cout << ((h[k] != null)?"Yes":"No") << "\n";
		}
	}
}