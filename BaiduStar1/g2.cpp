#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];

// 0x408024 0x408024 + 4

int main() {
	int *ptr = a;

	int n;

	cin >> n;

	for (int i = 1; i <= n; i ++) cin >> a[i];
	// 
	for (int i = 1; i <= n; i ++) {
		ptr ++;

		cout << *ptr << " Address:" << ptr << "\n";
	}
}