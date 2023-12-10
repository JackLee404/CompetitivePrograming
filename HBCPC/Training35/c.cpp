#include <iostream>
#include <vector>

using i64 = long long;

const int N = 10;

int n, m;

int num[N], cnt;

bool check1(std::vector<int>& a) {

	for (auto x: a) {
		if (x % 2 == 0) return false;
	}	
	return true;
	
}

bool check2(std::vector<int>& a) {
	for (int i = 0, j = (int) a.size() - 1; i < j; i ++, j --) {
		if (a[i] != a[j]) return false;
	}
	return true;
}

int main() {
	std::cin >> n >> m;

	int res = 0;

	for (int i = n; i <= m; i ++) {
		int x = i;

		std::vector<int> nums;

		while (x) {
			nums.push_back(x % 9), x /= 9;
		}

		res += (check1(nums) && check2(nums));
	}

	std::cout << res;
}