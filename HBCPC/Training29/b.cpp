#include <bits/stdc++.h>

using namespace std;

const char f[][100] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
	char c;
	cin >> c;
	if (c == '-') {
		cout << "fu";
	}else cout << f[c - '0'];
	while(cin >> c) {
		cout << " " << f[c - '0'];
	}
}