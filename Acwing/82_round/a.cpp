#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k, a[1010];
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	cout << a[n - k + 1];
}