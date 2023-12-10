#include <iostream>
#include <map>
using namespace std;

bool st[256], st2[256];

map<string, bool> mp;

int main() {
	st['H'] = st['D'] = st['C'] = st['S'] = true;
	st2['A'] = st2['T'] = st2['J'] = st2['Q'] = st2['K'] = true;
	for (int i = 2; i <= 9; i ++) {
		st2[i + '0'] = true;
	}
	int n;
	bool res = true;
	cin >> n;
	while (n --) {
		string t;
		cin >> t;
		if (!st[t[0]] || !st2[t[1]] || mp[t]) {
			res = false;
		}
		mp[t] = true;
	}
	cout << (res?"Yes":"No") << endl;
}