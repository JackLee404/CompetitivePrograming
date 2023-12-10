#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;

map<string, bool> st;

vector<string> v1;

int main() {
	int _;
	cin >> _;
	while (_ --) {
		string t;
		cin >> t;
		if (!st[t]) {
			st[t] = true;
			v1.push_back(t);
		}
	}
	for (int i = 0; i < (int) v1.size(); i ++) {
		cout << v1[i];
		if (i != (int) v1.size() - 1) {
			cout << endl;
		}
	}
}