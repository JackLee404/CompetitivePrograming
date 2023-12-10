#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l, a[300], b[300], c[300], dp[300];

bool wether[300];

// dp[i] 表示以当前第i个数结尾的子序列的最大长度
// 

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int t; cin >> t;
		a[t] = i, wether[i] = true;
	} 
	cin >> l;
	for (int i = 1; i <= l; i ++) cin >> c[i];
	for (int i = 1; i <= l; i ++) {
		if (!wether[i]) continue;
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j ++) {
			if (wether[j] && a[j] <= a[i]) {
				dp[i] = max(dp[i], dp[j + 1]);
			}
		}
	}
	cout << *max_element(dp + 1, dp + l);
}