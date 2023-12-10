#include <iostream>

using namespace std;

const int N = 1e6 + 10;

long long dp[1000][1000], a[1000][1000];

// dp[i][j] 表示第i层若选择该节点的最优解
// 则有 dp[i][j] = max(dp[i - 1][j + 1], dp[i - 1][j - 1]) + now

// 滚动
// for i in range(0, n):
// a[ti][j]

int b[9000][9000];

void out(int j, int i){
	if(j == 1) {
		cout << a[j][i];
	} else {
		out(j - 1, b[j][i]);
		cout << "-->" << a[j][i];
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j >= 1; j --) {
			cin >> a[i][j];
            if(dp[i - 1][j] > dp[i - 1][j - 1]) {
                b[i][j] = j;
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }else {
                b[i][j] = j - 1;
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            }
		}
	}
	long long ans = -1;
    int ai = 1;
	for(int i = 1; i <= n; i ++) {
		if (dp[n][i] > ans)
			ans = dp[n][i], ai = i;
	}
    cout << ans;
	cout << "[";
    out(n, ai);
    cout << "]";
}