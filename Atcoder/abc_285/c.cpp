#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long ans;

int main() {
	string a;
	cin >> a;
	reverse(a.begin(), a.end());
	for(int i = 0; i < a.size(); i ++) {
		int k = a[i] - 'A' + 1;
		ans += k * (long long) pow(26, i);
	}
	cout << ans;
}