#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int ps[2];

char a[N];

void solve() {
	int n;
	ps[0] = ps[1] = 0;
	cin >> n >> a + 1;

	for (int i = 1; i < n; i ++) {
		ps[a[i] - '0'] = i;	
		if (a[i] == '0') {
			cout << ps[1] + 1; // (n - x) + 1;
		} else {
			cout << ps[0] + 1; // (n - x) + 1;
		}
		cout << " ";
	}
	cout << endl;
}

int main() {
	int _;
	cin >> _;
	while (_ --) {
		solve();	
	}	
}