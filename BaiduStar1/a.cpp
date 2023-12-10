#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	int day = 0, sum = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++) {
			sum += i;
			day ++;

			if (day == n) {
				return cout << sum, 0;
			}
		}
	}
}