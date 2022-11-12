#include <iostream>

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

using namespace std;
typedef long long LL;

int a[200][200];
LL s[200][200];


int main() {
	a[1][1] = 1;
	for (int i = 1; i <= 100; i ++) {
		for (int j = 1; j <= 100; j ++)  {
			if (i == 1 && j == 1) continue;
			if (i == 1) a[i][j] = a[i][j - 1] + 2;
			else a[i][j] = a[i - 1][j] + 1;
		}
	}

	for (int i = 1; i <= 100; i ++) {
		for (int j = 1; j <= 100; j ++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	int ans = 0x3f3f3f3f;

	for (int n = 1; n <= 100; n ++) {
		for (int m = 1; m <= 100; m ++) {
			for (int i = 1; i <= 100 - n + 1; i ++) {
				for (int j = 1; j <= 100 - m + 1; j ++) {
					int x = i + n - 1;
					int y = j + m - 1;
					LL sum = s[x][y] - s[i - 1][y] - s[x][j - 1] + s[i - 1][j - 1];
					if (sum == 2022) {
						ans = min(ans, n * m);
					}
				}
			}
		}
	}

	// ans = 12
	cout << ans << endl;
}