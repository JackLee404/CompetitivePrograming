#include <bits/stdc++.h>

using namespace std;

int a[20];

int main() {
	string t; cin >> t;
	for (auto &x: t) {
		a[x - '0'] ++;
	}
	for(int i = 0; i <= 10; i ++) {
		if(a[i]){
			cout << i << ":" << a[i] << "\n";
		}
	}
}