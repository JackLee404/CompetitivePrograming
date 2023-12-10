#include <iostream>

using namespace std;

bool check[3010];

int main() {
	char t[3010];
	int n, last = 0;
	cin >> n;
	for (int i = 0; i <= n; i ++) check[i] = true;
	cin >> t + 1;
	for (int i = 1; i <= n; i ++) {
		// cout << "last=" << last << endl;
		if (t[i] == 'L') {
			for (int j = last; j <= i; j ++) {
				check[j] = false;
			}
			last = i + 1;
		} else if (t[i] == 'R') {
			int k, cnt = 0;
			for (k = i;k <= n && t[k] != 'L'; k ++, cnt ++) {
				check[k] = false;
			}
			cnt ++;
			if (k <= n) {
				check[k] = false;
				if (cnt % 2 != 0)
					check[(k + i) / 2] = true;	
			}
			i = k;
			last = i + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (check[i]) ans ++;
		// cout << check[i] << " ";
	}
	// cout << endl;
	cout << ans;
}