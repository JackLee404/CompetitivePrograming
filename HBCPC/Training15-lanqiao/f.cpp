#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;


int main() {
	int t, c, s;
	double v;
	cin >> t >> c >> s;
	v = c * 1.0 / t;
	s -= c;
	cout << (int) (s / v);
}