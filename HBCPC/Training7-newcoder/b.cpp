#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++) {
		int t;
		cin >> t;
		a[t] ++;
	}
	for (int i = 1; i <= q; i ++) {
		int x;
		cin >> x;
		cout << n - a[x] << endl;
	}
}