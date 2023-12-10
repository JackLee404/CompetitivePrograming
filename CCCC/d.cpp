#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n;
	
	std::cin >> n;
	
	while (n --) {
		int a, b, c;
		
		std::cin >> a >> b >> c;
		
		if (c == a * b) {
			puts("Lv Yan");
		} else if (c == a + b) {
			puts("Tu Dou");
		} else {
			puts("zhe du shi sha ya!");
		}
	}
}