#include <bits/stdc++.h>
const int M = 1e9 + 7;
using namespace std;
typedef __int128 i128;

int main() {
	i128 a,x2;
	int x;
	cin >> x;
	x2 = x;
	a = (i128(x2 * x2) * (1 + x2)) / 2;
	a -= (x2 * i128(x2 + 1) * (2 * x2 + 1)) / 6;
	a %= M;
	cout << (int) a << endl;
}