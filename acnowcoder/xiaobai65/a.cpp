#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define siz(x) (int)x.size()
#define IOS ios::sync_with_stdio(false);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define dbg1(a) cout << a << endl;
#define dbg2(a, b) cout << a << " " <<  b << endl;
#define dbg3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0; 
        return a;
    }
    int d = exgcd(b, a % b, x ,y);
    int tmp = x;
    x = y,y = tmp - a / b * y;
    return d;
}

long long dp[N][2], a[10];

int main() {

	int n;

	cin >> n >> a[1] >> a[2];
	

	for (int i = 1; i <= 2; i ++) {
		for (int j = 1; j <= n; j ++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i] && dp[i][j - a[i]] + a[i] <= n)
				dp[i][j] = max(dp[i][j], dp[i][j - a[i]] + a[i]);
		}
	}

	cout << n - dp[2][n] << endl;
}