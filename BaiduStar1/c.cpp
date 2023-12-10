#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	int day = 0, ans = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++) {
			ans += i;

			day ++;

			if (day == n) {
				cout << ans;
				return 0;
			}
		}
	}
}