#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 1e5 + 10, M = 100003;

int mod;

int h[N], e[N], ne[N], idx;

void insert(int x) {
	int n = (x % M + M) % M;
	ne[idx] = h[n], h[n] = idx, e[idx ++] = x;
}

bool find(int x) {
	int n = (x % M + M) % M;
	for(int i = h[n]; ~i; i = ne[i]) {
		if(e[i] == x) return true;
	}
	return false;
}

int main() {
	memset(h, -1, sizeof h);
	
// 	for(int i = 1e5; ; i ++) {
// 	    bool ok = true;
// 	    for(int j = 2; j <= i / j; j ++) {
// 	        if(i % j == 0) {
// 	            ok = false;
// 	            break;
// 	        }
// 	    }
// 	    if(ok) {
// 	        std::cout << i << "\n";
// 	        break;
// 	    }
// 	}

	int n;

	std::cin >> n;


	while(n --) {
		std::string t;
		int x;

		std::cin >> t >> x;

		if(t == "I") {
			insert(x);
		} else {
			std::cout << (find(x)?"Yes":"No") << "\n";
		}
	}
}