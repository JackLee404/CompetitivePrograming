#include <iostream>

using namespace std;

bool prime(int x) {
	bool ok = true;
	if(x < 2) return false;
	for(int i = 2; i <= x / i; i ++) {
		if(x % i == 0) ok = false;
	}
	return ok;
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i < (1 << n); i ++) {
		int k = (i<<i) - 1;
		if(prime(k)) cout << i << "\n";
	}
}