/*
	property: 相邻的黑白不需要反转
	BBBBWBWWW
	如果我们迫切的想要反转BW
	为
	BBBBBWWWW 只需要3次操作
	这个性质是错的
	
	不管怎么反转 每个数只进行最多一次操作
	
	如果一次操作不能使相邻的数相同 我们取消该次操作
*/

#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
	int n;
	std::string t;

	std::cin >> n >> t;

	std::vector<int> act1, act2;

	int ans1, ans2;

	ans1 = ans2 = 0;


	bool a1 = true, a2 = true;

	for(auto &x: t) {
		if(x != 'W') a1 = false;
		if(x != 'B') a2 = false;
	}

	if(a1 || a2) {
		return puts("0"), (void) 0;
	}


	auto flip = [](char &a) {
		a = (a == 'W'?'B':'W');
	};
	
	std::string t2 = t;


	for(int i = 0; i < (int)t2.size() - 1; i ++) {
		flip(t2[i]), flip(t2[i + 1]);	

		if(t2[i] != 'W') {
			flip(t2[i]), flip(t2[i + 1]);
		} else {
			ans1 ++, act1.push_back(i);
		}
	}

	bool st1 = true;

	for(auto &x: t2) {
		if(x != 'W') st1 = false;
	}

	if(!st1) ans1 = 0x3f3f3f3f;
	
	t2 = t;

	for(int i = 0; i < (int) t2.size() - 1; i ++) {
		flip(t2[i]), flip(t2[i + 1]);	

		if(t2[i] != 'B') {
			flip(t2[i]), flip(t2[i + 1]);
		} else {
			ans2 ++, act2.push_back(i);
		}
	}

	bool st2 = true;
	
	
	for(auto &x: t2) {
		if(x != 'B') st2 = false;
	}

	if(!st2) ans2 = 0x3f3f3f3f;

	if(!st1 && !st2) {
		puts("-1");
	} else if(ans1 < ans2) {
		std::cout << ans1 << "\n";

		for(int i = 0; i < ans1; i ++) {
			std::cout << act1[i] + 1 << " \n"[i == ans1 - 1];
		}
	} else {
		std::cout << ans2 << "\n";

		for(int i = 0; i < ans2; i ++) {
			std::cout << act2[i] + 1 << " \n"[i == ans2 - 1];
		}
	}
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}