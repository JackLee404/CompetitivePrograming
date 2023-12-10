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
		LL n, m, a[N], res = 0, sum = 0;
		bool check = false;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			res += a[i] / 2;
			sum += a[i];
		}

		if (m > res) {
			cout << -1 << endl;
			continue;
		}
		
		while (!check) {
			for (int i = 1; i <= n; i ++) {
				if ((a[i] - 1) / 2 <= a[i] / 2) {
					res --, sum --, a[i] --;
					if (res < m) {
						cout << sum + 1 << endl;
						check = true;
						break;
					}
				}
			}
		}
		if (!check) {
			cout << -1 << endl;
		}
	}
}