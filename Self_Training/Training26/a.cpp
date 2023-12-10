#include <iostream>
#define INF 0x3f3f3f3f
using i64 = long long;

int l = -INF, r = INF;

int main() {
	int n;
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		int a, b, tl, tr;
		
		std::cin >> a >> b;
		
		int tk = a / b;
		
		while ((tk - 1) && a / (tk - 1) == b) {
			tk --;
		}
		
		tl = tk, tr = a / b;
		
		l = std::max(l, tl);
		r = std::min(r, tr);
 	}
	
	std::cout << l << " " << r;
	
	return 0;
} 