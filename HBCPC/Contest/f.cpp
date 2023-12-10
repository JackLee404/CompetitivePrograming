#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int main() {
	int t;
	cin >> t;
	while (t --) {
		LL n, m, a[N];
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1, greater<LL>());

		LL now = 0, pir = 0;
		for (int i = 1; i <= n; i ++) {
			LL k = a[i] / 2;
			if (pir == m) {
				now ++;
			} else {
				if (a[i] % 2 == 0) {
					if (a[i] % 2 == 0) {
						if (pir + k - 1 > m) {
							now += (m - pir) * 2 + 1;
							pir = m;
						} else {
							now += a[i] - 1;
							pir += k - 1;
						}
					} else {
						if (pir + k > m) {
							now += (m - pir) * 2 + 1;
							pir = m;
						} else {
							now += a[i];
							pir += k;
						}
					}
				}
			}
		}

		cout << now << " " << pir << endl;		
	}
}