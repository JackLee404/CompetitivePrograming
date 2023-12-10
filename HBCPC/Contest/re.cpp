#include <iostream>

using namespace std;
const int N = 1e6 + 10, ED = 31623;

int a[N];

// int binary_search(int l, int r) {
// 	while (l < r) {
// 		int mid = l + r >> 1;
// 		if (a[mid].second)
// 	}
// }

int main() {
	pair<int, int> v[N];
	v[1] = {1, 1};
	a[1] = 0, a[2] = 1;
	int res = 1;
	for (int i = 2; i <= ED; i ++) {
		v[i] = {v[i - 1].first + 2, v[i - 1].second + 1};
		res += v[i].second * 2;	
		if (i > 2) {
			a[i] = v[i - 1].first * v[i - 1].second + (v[i - 1].first - 1) * v[i].second;
		}
		cout << a[i] << endl;
	}


	// int _;
	// cin >> _;
	// while (_ --) {
	// 	int n;
	// 	cin >> n;
	// 	int t = n;
	// }
}