#include <bits/stdc++.h>

using i64 = long long;

int n;

std::string t;

bool check(int k) {
	std::string st = t.substr(0, k);

	for(int i = k; i + k - 1 < n; i += 1) {
	    std::cout << t.substr(i, k) << "\n";
		if(t.substr(i, k) != st) {
			return false;
		}	
	}

	return true;
}

int main() {
	std::cin >> n >> t;

	int l = 1, r = n - 1;
    
    check(3);

// 	while(l < r) {
// 		int mid = l + r >> 1;
// 		// std::cout << mid << "\n";
// 		if(check(mid)) l = mid + 1;
// 		else r = mid;
// 	}

// 	std::cout << l;
}