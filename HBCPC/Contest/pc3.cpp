#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int main() {
	int t;
	cin >> t;
	while (t --) {
		LL n, m, a[N], ou = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			if (a[i] % 2 == 0)
				ou ++, a[i] --;
		}

		sort(a + 1, a + n + 1, greater<LL>());
		LL now = 0, pir = 0;

		for (int i = 1; i <= n; i ++) {
			LL need = m - pir;
			if (need == 0) {
				now ++;
			} else if (need * 2 > a[i]) {
				now += a[i];
				pir += a[i] / 2;
			} else if (need * 2 < a[i]) {
				now += need * 2;
				pir = m;
			}
		}

		if (pir < m) {
			if (ou < m - pir)
				cout << -1 << endl;		
			else
				cout << now + m - pir << endl;
		} else {
			cout << now << endl;
		}
	}
}