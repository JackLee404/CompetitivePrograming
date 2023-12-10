#include <bits/stdc++.h>

using namespace std;

void solve() {
	vector<string> a;
	bool ck1, ck2;
	ck1 = ck2 = false;
	while (true) {
		string t; cin >> t;
		a.push_back(t);
		int k = (int) t.size() - 1;
		if (t[k] == ',') {
			if (t.size() > 4) {
				if (t[k - 1] == 'g' && t[k - 2] == 'n' && t[k - 3] == 'o') {
					ck1 = true;
				}
			}	
		}
		if (t[k] == '.') {
			if (t.size() > 4) {
				if (t[k - 1] == 'g' && t[k - 2] == 'n' && t[k - 3] == 'o') {
					ck2 = true;
				}
			}	
			break;
		}
	}
	if (ck1 && ck2) {
		int len = a.size() - 1;
		a[len] = "zhong.", a[len - 1] = "ben", a[len - 2] = "qiao";
		for (int i = 0; i < a.size(); i ++) {
			cout << a[i] << " \n"[i == len]
		}
	} else {
		puts("Skipped");
	}
}

int main() {
	int n;
	cin >> n;
	while (n --) {
		solve();
	}
}