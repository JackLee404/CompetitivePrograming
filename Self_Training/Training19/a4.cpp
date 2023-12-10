#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using i64 = long long;

const int N = 1e5 + 10;

struct node {
	int a, b;
} arr[N];

int n, sum[N], q[N], q2[N];

node mx1[N], mx2[N];

/*
	按疲劳值排序，先保证前i个疲劳值最大，然后比较
	1. 前i个最大值 + 最大距离 \times 2
	2. 舍去一个最小值 (假设后面存在一个更大距离和疲劳值的组合， 若不存在更大的距离那么肯定小于1. 所以我们假设该数就是最大距离)
*/

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> arr[i].a;

	for (int i = 1; i <= n; i ++) std::cin >> arr[i].b;

	std::sort(arr + 1, arr + 1 + n, [](node x, node y) {
		return x.b > y.b;
	});

	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + arr[i].b;
		q[i] = std::max(q[i - 1], arr[i].a * 2);
	}

	for (int i = n; i >= 1; i --) {
		q2[i] = std::max(q2[i + 1], arr[i].a * 2 + arr[i].b);
	}
	
	for (int i = 1; i <= n; i ++) {
		std::cout << std::max(sum[i] + q[i], q2[i] + sum[i - 1]) << "\n";
	}
}