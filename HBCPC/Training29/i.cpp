#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v1;
stack<char> s1;

int main() {
	int pos = 0;
	bool ok = true;
	string a, b; cin >> a >> b;
	reverse(a.begin(), a.end());
	while(true) {
		if(!a.size()) break;

		if(pos >= b.size()) break;

		if(a.back() == b[pos]) {
			a.pop_back(), pos ++;
			v1.push_back({1, 2});
		} else if(s1.size() && s1.top() == b[pos]){
			s1.pop(), pos ++;
			v1.push_back({3, 2});
		} else {
			s1.push(a.back()), a.pop_back();
			v1.push_back({1, 3});
		} 
	}

	while(pos < b.size() && s1.size() && s1.top() == b[pos]) pos ++, s1.pop(), v1.push_back({3, 2});

	if(!s1.empty()) {
		cout << "Are you kidding me?";
	} else {
		for (auto &x: v1) {
			cout << x.first << "->" << x.second << "\n";
		}
	}
}