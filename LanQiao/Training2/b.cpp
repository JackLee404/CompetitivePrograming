#include <iostream>

using i64 = long long;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
 1234
 1234 % 10 = 4

 123 % 10 = 3
 12 % 10 = 2
 1 % 10 = 1
 
*/

int count(int x) {
	int res = 0;

	while(x > 0) {
		res += x % 10;
		x /= 10;
	}

	return res;
}

int main() {

	int cnt = 0;

	for(int y = 1900; y <= 9999; y ++) {
		if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) days[2] = 29;
		else days[2] = 28;


		for(int m = 1; m <= 12; m ++) {
			for(int j = 1; j <= days[m]; j ++) {
				int k1 = count(y), k2 = count(m) + count(j);

				if(k1 == k2) {
					cnt ++;

					// std::cout << y << " " << m << " " << days[m] << "\n";
				}
			}
		}
	}

	std::cout << cnt;
}