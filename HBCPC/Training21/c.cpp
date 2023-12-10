#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int n, m, now = 1, record[N];

vector<int> a[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++){
			int t; cin >> t;
			a[i].push_back(t);
		}
	}
	while (m --) {
		int n1, n2, n3; cin >> n1;
		if (!n1) {
			cin >> n2;
			now = a[now][n2 - 1];
		} else if (n1 == 1) {
			cin >> n2; record[n2] = now;
			cout << now << "\n";
		} else {
			cin >> n3; now = record[n3];
		}
	}
}