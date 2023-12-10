#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> m >> n;
	long long sum = 0;
	int cnt = 1;
	for (int i = 1; i <= m; i ++) {
		int t;
		cin >> t;
		if (sum + t > n) {
			sum = t;
			cnt ++;
		} else sum += t;
	}
	cout << cnt;
}