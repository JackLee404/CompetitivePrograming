#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool check1(vector<int> &a) {
	for (int x: a) {
		if (x % 2 == 0) return false;		
	}

	return true;	
}

bool check2(vector<int> &a) {
	int len = a.size();

	for (int i = 0, j = len - 1; i < j; i ++, j --) {
		if (a[i] != a[j]) return false;
	}

	return true;
}

int main() {
	cin >> n >> m;

	int ans = 0;

	for (int i = n; i <= m; i ++) {
		int x = i;

		vector<int> v1;	

		while (x) {
			v1.push_back(x % 9);
			x /= 9;
		}

		if (n == 0) v1.push_back(0);	

		if (check1(v1) && check2(v1)) {
			ans ++;	
		}
	}

	cout << ans;
}