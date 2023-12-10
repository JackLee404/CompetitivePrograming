#include <iostream>

using namespace std;

const int N = 1e5 + 10;

struct ticket {
	int time; // 表示时间
	int price; // 表示价格
	bool used; // 表示票有没有被用过
} q[N];

int hh = 0, tt = -1;

// 输入保证了时间是递增的

int main() {
	int n;

	cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; i ++) {
		int type, tm, pc;

		cin >> type >> tm >> pc;

		if (type) {
			while (hh <= tt && tm - q[hh].time > 45) hh ++; // 队把超过45分钟的票都出

			bool ok = false;

			for (int i = hh; i <= tt; i ++) {
				if (q[i].price >= pc) {
					q[i].used = ok = true;
				}
			}

			if (!ok) ans += pc;

		} else {
			q[++ tt] = {tm, pc, false};
			ans += pc;
		}
	}

	cout << ans;
}