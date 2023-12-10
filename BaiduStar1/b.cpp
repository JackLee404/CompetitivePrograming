#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int cnt[N];

int main() {
	int a[4];

	// memset(cnt, 0, sizeof cnt);

	for (int i = 1; i <= 3; i ++) cin >> a[i];

	for (int i = 1; i <= a[1]; i ++) {
		for (int j = 1; j <= a[2]; j ++) {
			for (int k = 1; k <= a[3]; k ++) {
				cnt[i + j + k] ++;
			}
		}
	}

	int maxn = 1;

	for (int i = 1; i <= a[1] + a[2] + a[3]; i ++) {
		if (cnt[i] > cnt[maxn]) maxn = i;
	}

	cout << maxn;
}