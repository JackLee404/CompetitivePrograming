#include <bits/stdc++.h>
typedef pair<int, int> PII
using namespace std;

int a[10][10];


int main() {
	vector<int> b;
	for (int i = 0; i < 10; i ++) {
		string c;
		cin >> c;
		for (int j = 0; j < 10; j ++) {
			if (c[j] == '#') {
				a[i][j] = 1;

			}
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			for (int k = j + 1; k < n; k ++) {
				for (int m = k + 1; m < n; m ++) {
					if (cal(i, j) == cal(k, m) && cal(i, j))
				}	
			}
		}
	}
}