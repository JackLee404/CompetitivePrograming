#include <iostream>

using namespace std;

const int N = 3e4 + 10;

int v[N], w[N], s[N], dp[N];

int main() {
    int n, m, cnt = 0; 
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int v1, w1, s1; 
        cin >> v1 >> w1 >> s1;
        int sum = 0;
        for (int k = 1; sum + k <= s1; k<<=1) {
            v[++cnt] = k * v1, w[cnt] = k * w1;
            sum += k;
            // s1 -= k;
        }
        if (s1 > 0) {
            v[++cnt] = s1 * v1, w[cnt] = s1 * w1;
        }
    }
    for (int i = 1; i <= cnt; i ++) {
        for (int j = m; j >= v[i]; j --) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m];
}