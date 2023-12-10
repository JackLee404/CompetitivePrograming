#include <iostream>

using namespace std;

const int N = 2e5 + 10;

struct ticket {
	int price;
	int time;
	bool used;
} q[N];

int hh = 0, tt = -1;

int main() {
	int n;

	cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; i ++) {
		int x, y, z;

		cin >> x >> y >> z;

		if (x) {
			while (hh <= tt && z - q[hh].time> 45) hh ++;

			bool ok = false;

			for (int i = hh; i <= tt; i ++) {
				if (!q[i].used && q[i].price >= y) {
					// cout << q[i].price << " " << y << "\n";
					q[i].used = ok = true;
					break;
				}
			}

			ans += (ok? 0: y);

		} else {
			q[++ tt] = {y, z, false};
			ans += y;
		}
	}

	cout << ans;
}