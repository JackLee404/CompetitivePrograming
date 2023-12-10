#include <iostream>
#include <vector>

using i64 = long long;

int n;

std::vector<std::pair<int, int>> v1;

int main() {	
	std::cin >> n;

	for(int i = n; i >= 0; i --){
		int a;
		std::cin >> a;
		if(a) {
			v1.push_back({a, i});
		}
	}

	if(v1.empty()) {
		std::cout << 0;
		return 0;
	}

	for(int i = 0; i < v1.size(); i ++) {
		std::pair<int, int> &t = v1[i];
		if(!i && t.first > 0) {
			if(t.first != 1) {
				std::cout << t.first;
			} else if(t.first == 1 && t.second == 0) {
	 			std::cout << 1;
	 		}
		} else {
			if(t.first == 1 && t.second > 0){
				std::cout << "+";
			} else if(t.first == -1 && t.second > 0) {
				std::cout << "-";
			} else if(t.first > 0 || (t.first == 1 && t.second == 0)) {
				std::cout << "+" << t.first;
			} else if(t.first < 0 || (t.first == -1 && t.second == 0)){
				std::cout << t.first;
			}
		}

		if(t.second > 1) {
			std::cout << "x^" << t.second;
		} else if(t.second == 1) {
			std::cout << "x";
		}
	}
}