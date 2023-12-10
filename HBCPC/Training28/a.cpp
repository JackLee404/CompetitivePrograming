#include <iostream>
#include <queue>
using namespace std;

const int N = 200;

int a[N], b[N], dp1[N], dp2[N];

// dp[i][j] 表示以第i个同学为山峰的最小出队数
// 

int main() {
	int n; cin >> n;
	for(int i = 1, j = n; i <= n; i ++, j --) {
		cin >> a[i];
		b[j] = a[i];
	}

	/* 左侧递增子序列 */
	for(int i = 1; i <= n; i ++) {
        dp1[i] = 1;
		for (int j = 1; j < n; j ++) {
			if (a[j] < a[i])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}

	/* 右侧递减子序列 */
	for(int i = 1; i <= n; i ++) {
        dp2[i] = 1;
		for(int j = 1; j < i; j ++) {
			if(b[j] < b[i]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
//     for (int i = 1; i <= n; i ++) {
//         cout << b[i] << " \n"[i == n];
//     }
    for (int i = 1; i <= n; i ++) {
        cout << dp2[i] << " \n"[i == n];
    }
	int ans = 0x3f3f3f3f;
    //dp2[1] --> n n - i + 1
	for(int i = 1; i <= n; i ++) {
		int mx1 = -1, mx2 = -1, tot = 0;
		for(int j = 1; j < i; j ++) {
			if (a[j] < a[i])
				mx1 = max(dp1[j], mx1);
		}
		if (mx1 != -1) tot += i - 1 - mx1;
        else tot += (i - 1);
		for(int j = i + 1; j <= n; j ++) {
			if (b[n - j + 1] < a[i])
				mx2 = max(dp2[n - j + 1], mx2);
		}
		if (mx2 != -1) tot += n - i - mx2;
        else tot += (n - i);
//         cout << mx1 << " " << mx2 << endl;
		ans = min(tot, ans);
	}
	cout << ans;
}