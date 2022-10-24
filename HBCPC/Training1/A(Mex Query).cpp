#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2 * 1e5 + 10;

int a[N];

int main() {
	int _;
	cin >> _;
	while (_ --) {
		int t;
		bool flag = false;
		cin >> t;
		
		for (int i = 0; i < t; i ++) {
			cin >> a[i];
		}
		
		sort(a, a + t);
		
		
		if (a[0] != 0) {
			cout << 0 << endl;
			continue;
		}
		
		for (int i = 1; i < t; i ++) {
			if (a[i] - a[i - 1] > 1) {
				cout << a[i - 1] + 1 << endl;
				flag = true;
				break;
			}
		}
		if (!flag) cout << t << endl;
	}
}


// 0 1 1 4 2 5 ---> 0 1 1 2 4 5



