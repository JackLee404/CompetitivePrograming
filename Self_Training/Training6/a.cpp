#include <iostream>

using i64 = long long;

int main() {
	int m;
	std::cin >> m;

	int curr_sum = 0, j = 0;

	for(int i = 1; i <= 2000000; i ++) {
		curr_sum += i;

		while(curr_sum > m) {
			curr_sum -= j;
			j ++;
		}

		if(curr_sum == m && i - j != 0) {
			std::cout << j << " " << i << std::endl;
		}	
	}
}