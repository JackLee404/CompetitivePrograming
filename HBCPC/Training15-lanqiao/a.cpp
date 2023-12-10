#include <iostream>

using namespace std;

int main() {
	long long k;
	for (int j = 1;; j ++) {
		int cnt = 0;
		k = 2022 + j;
		for (int i = 0; (k >> i) > 0; i ++) {
			cout << (k >> i & 1);
			if ((k >> i & 1) == 0) {
				cnt ++;
			} else {
				break;
			}
		}
		cout << endl;
		if (cnt == 6) {
			cout << k << endl;
			break;
		}
	}
	
}
