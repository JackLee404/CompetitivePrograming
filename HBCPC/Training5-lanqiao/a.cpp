#include <iostream>

// 1题 11

using namespace std;

int date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int now = 5;

int main() {
	int cnt = 0;
	for (int i = 1; i <= 12; i ++) {
		for (int j = 1; j <= date[i]; j ++) {
			now ++;
			if (now == 8) now = 1;
			if (j == 1 || j == 11 || j == 21 || j == 31 || now == 6 || now == 7) {
				cnt ++;
			}
		}
	}
	cout << cnt << endl;
}