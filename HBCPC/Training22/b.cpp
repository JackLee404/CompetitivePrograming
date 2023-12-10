#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	return b == 0?a:gcd(b, a % b);
}

int main() {
	int n, last; cin >> n;
	vector<int> a(n);
	last = 0;
	for (int i = 0; i < a.size(); i ++) {
		cin >> a[i];
		if (a[i]<0) a[i]*=-1;
		last = gcd(last, a[i]);
	}
	cout << last;
}