#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5;

int dp[N], a[N], pre[N], len[N];

// dp[i] 表示从1~i跳过的点数之和最小值
// dp[i] = min(dp[i])
// len[i] 表示当前dp的路径长度
// 要想让字典序最小，则需要让小数靠前，并且长度最短

int getmin(int x) {
	int mx = 0, mn = 0x3f3f3f3f;
	for(int i = 3; i >= 1; i --) {
		if(x - i < 0) continue;
		if(dp[x - i] < mn){
			mx = x - i;
			mn = dp[x - i];
		}else if(dp[x-i] == mn && len[x - i] > len[mx]) {
			mx = x - i;
		}
	}
	return mx;
}

void out(int u) {
	if(u == 0) {
		cout << 0;
		return;
	}else {
		out(pre[u]);
		cout << " " << u;
	}
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i <= n; i ++){
		cin >> a[i];
	}
	// memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i <= n + 1; i ++){
		if(i == 0) {
			dp[i] = a[0], len[i] = 1;
			continue;
		}
		int mx = getmin(i);
		pre[i] = mx;
		len[i] = len[mx] + 1;
		dp[i] = dp[mx] + a[i];
	}
	cout << dp[n + 1] << "\n";
	out(pre[n + 1]);
}