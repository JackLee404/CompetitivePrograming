#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

int trans(int x) {
	int k = x, cnt = 0;
	int res = 0;
	while (k > 0) {
		// cout << k % 10;	
		res += (k % 10) * (int) pow(16, cnt ++);
		k /= 10;
	}
	// cout << res;
	return res;
}


int main() {
	for (int i = 10; ; i ++) {
		if (trans(i) % i == 0) {
			cout << i << endl;
			break;	
		}
	}
}
