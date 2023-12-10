#include <bits/stdc++.h>
// #inclue
using i64 = long long;

const int N = 5e5;

std::vector<std::string> v1;

int main() {


	while (true) {
		v1.clear();
		v1.push_back("0");

		for (int i = 1; i <= 52; i ++) {
			std::string x;
			std::cin >> x;
			
			if (i == 1) {
				if (x == "#") {
					return 0;
				}
			}

			int cnt = 0;

			for (int j = i - 1; j >= 1 && cnt <= 3; j --) {
				if (v1[j] == "0") continue;

				cnt ++;

				if (cnt == 1) {
					if (v1[j] == x) {
						
					}
				} else {

				}
 			}
		}

	}	
}