#include <iostream>

using namespace std;

bool b[7][7];

int main() {
	int a[7], n;
	for (int i = 1; i <= 6; i ++) {
		cin >> a[i];
	}
	cin >> n;
	for (int i = 1; i <= 6; i ++) {
		int cnt = 0;
		for (int j = 6;; j --) {
			if (j != a[i]) cnt ++;
			if (cnt >= n) {
				cout << j << " ";
				break;
			}
		}
	}
}