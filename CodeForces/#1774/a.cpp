#include <iostream>


using namespace std;


int main() {
	int t;
	cin >> t;
	while (t --) {
		int sum = 0, n;
		string t, ans;
		cin >> n >> t;
		sum += t[0] - '0';
		// cout << t << endl;
		for (int i = 1; i < t.size(); i ++) {
			if (t[i] == '0') {
				cout << "+";
			} else {
				if (sum > 0) {
					sum -= 1;
					cout << "-";
				} else if (sum < 0) {
					sum += 1;
					cout << "+";
				} else {
					sum += 1;
					cout << "+";
				}
			}
		}
		cout << endl;
	}
}