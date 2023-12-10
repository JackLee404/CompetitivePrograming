#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int ans;

// 负权与负权，保证较小的俩数的相乘
// 默认大顶堆
priority_queue<int> p1, p2;
priority_queue<int> q1, q2;

vector<int> v1, v2, c1, c2;


// 正数排序， 负数排序
// 正数递增， 负数递减

int main() {
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		int t; cin >> t;
		if(t < 0) v2.push_back(t);
		else v1.push_back(t);
	}
	cin >> m;
	for(int i = 1; i <= m; i ++) {
		int t; cin >> t;
		if(t < 0) c2.push_back(t);
		else c1.push_back(t);
	}
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end());
	sort(c1.begin(), c1.end(), greater<int>());
	sort(c2.begin(), c2.end());

	int k = min(v1.size(), c1.size());
	for(int i = 0; i < k; i ++) {
		ans += v1[i] * c1[i];
	}
	int k2 = min(v2.size(), c2.size());
	for(int i = 0; i < k2; i ++) {
		ans += v2[i] * c2[i];
	}
	cout << ans;
}