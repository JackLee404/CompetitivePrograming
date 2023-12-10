#include <iostream>

using i64 = long long;

int pos[4];

int count(int x) {
	int res = 0;
	int cnt = 0;
	for (int i = 31; i >= 0; i --) {
		if (x >> i & 1) {
			res += (x >> i & 1);
			if (cnt < 3)
				pos[++ cnt] = i;
		}
	}
	return res;
}

void solve() {	
	i64 n;

	std::cin >> n;

	int num = count(n);

	i64 ans = 0;

	if (num >= 3) {
		ans = (1ll << pos[1]) + (1ll << pos[2]) + (1ll << pos[3]);
	} else if (num == 2) {
		if (pos[2] >= 2) {
			ans = (1ll << pos[1]) + (1ll << pos[2] - 1) + (1ll << pos[2] - 2);
		} else {
 			return puts("-1"), (void) 0;
 		}
	} else if (num == 1) {
		if (pos[1] >= 3) {
			// puts("??↓");
			ans = (1ll << pos[1] - 1) + (1ll << pos[1] - 2) + (1ll << pos[1] - 3);
		} else {
			return puts("-1"), (void) 0;
		}
	} else return puts("-1"), (void) 0;

	std::cout << ans << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}