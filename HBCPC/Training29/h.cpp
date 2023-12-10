#include <bits/stdc++.h>

using namespace std;

char a[100][100];

int n;

bool check() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (a[i][j] != '*') return false;
		}
	}
	return true;
}

void out() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cout << a[i][j] << " \n"[j == n];
		}
	}
}

int main() {
	cin >> n;
	n *= 2;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	int k; cin >> k;
	while(k --) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if(a[x1][y1] != a[x2][y2]) {
			if (cnt + 1 == 3) {
				cout << "Game Over" << "\n";
			} else
				cout << "Uh-oh" << "\n", ++ cnt;
		} else {
			if(check()) {
				cout << "Congratulations!" << "\n";
			} else {
				out();
			}
		}
	}
}