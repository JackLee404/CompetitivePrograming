#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;


int a[N][6], t[1000], dp[N][6];

void init() {
	for (int i = 0; i <= 1000; i ++) {
		if (!i) t[i] = 1;
		else t[i] = t[i - 1] * 3;
	}
}

int main() {
	int n, m, k;
	cin >> n >> m;
	cin >> k;
	bool flag = false;
	for (int j = 1; j <= m; j ++) {
		cin >> a[k][j];
		if (j - 1 && a[k][j] == a[k][j - 1]) {
			flag = true;
		}
	}

	if (flag) {
		cout << 0;
		return 0;	
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (i == k) {
				continue;
			}
		}
	}		
}