#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;

int n, m, k, a[N];

int main() {
	int _;
	cin >> _;
	while (_ --) {
		int cnt = 0;
		cin >> n >> m >> k;

		bool ok = true;

		int unit = ceil(n * 1.0 / k);

		int last;
		
		if (n % k == 0) last = k;
		else last = n % k;

		for (int i = 1; i <= m; i ++) {
			cin >> a[i];
			if (a[i] > unit) {
				ok = false;
			} else if(a[i] == unit) {
				cnt ++;
			}
		}

		if (ok == false || cnt > last) {
			puts("NO");
		} else {
			puts("Yes");
		}
	}
}