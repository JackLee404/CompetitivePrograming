#include <iostream>

using namespace std;

const int N = 3e3 + 10;

int n, m;

int a[N], sum[N];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}

	int ans = 0x3f3f3f3f;


	for (int i = 1, j = 1; i <= n - m; i ++) {
		while (j - i + 2 <= m) j ++;
		
		ans = min(ans, sum[j] - sum[i - 1]);
	}

	cout << ans;
}