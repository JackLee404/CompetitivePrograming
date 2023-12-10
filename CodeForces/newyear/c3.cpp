#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// 3 / 2 = 1
// 

int fast_pow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b>>=1;
	}
	return ans;
}

int main() {
	int a, b;
	while (cin >> a >> b)
		cout << fast_pow(a, b) << "\n";
}