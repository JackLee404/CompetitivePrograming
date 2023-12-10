#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 20;


int n, m;

int d[N][N], dp[20][1 << 1];

void init() {
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i ++) {
		dp[i][i] = 0;
	}
}

void floyd() {
	for (int k = 1; k <= n; k ++)  {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}


int main() {
	int _;
	cin >> _;
	while (_ --) {
		cin >> n >> m;

		init();
		memset(dp, 0x3f, sizeof dp);

		for (int i = 0; i < m; i ++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (d[a][b] != INF)
				d[a][b] = d[b][a] = min(d[b][a], c);
			else
				d[a][b] = d[b][a] = c;
		}

		if (n == 1) {
			cout << 0 << endl;
			continue;
		}

		floyd();

		for (int i = 1; i <= n; i ++) {
			dp[i][0] = d[i][1];
		}

		dp[1][1] = 0;

		for (int j = 1; j < 1 << n; j ++) {

			for (int i = 1; i <= n; i ++) {
				if (j & (1 << i - 1) == 0) continue;
				for (int k = 1; k <= n; k ++) {
					if (j & (1 << k - 1) == 1)  continue;
					dp[i][j] = min(dp[i][j], d[i][k] + dp[k][j ^ (1 << k - 1)]);
				}

			}
		}		
			

		printf("%d\n", dp[1][(1 << n) - 2]);
	}
}