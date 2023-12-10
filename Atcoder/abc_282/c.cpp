#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int n, cnt;
// bool check[N];
char a[N];

int main() {
	cin >> n;
	cin >> a + 1;
	// for (int i = 1; i <= n; i ++) {
	// 	if (a[i] == '\"') {
	// 		cnt ++;
	// 	}
	// }

	// cnt /= 2;

	// for (int i = 1; i <= 2 * cnt; i ++) {

	// }

	bool check = false;

	for (int i = 1; i <= n; i ++) {
		if (a[i] == '\"' && !check) {
			check = true;		
		} else if (a[i] == '\"' && check) {
			check = false;
		} else if (!check) {
			if (a[i] == ',') a[i] = '.';
		}
	}
	cout << a + 1;
}