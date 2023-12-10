#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define siz(b) (int)b.size()
using namespace std;

typedef long long LL;

// lanqiao
// lanqiaoaiqnal
// bananab

// 枚举末尾

int main() {
	string t, b, ans;
	cin >> t;
	b = t;
	reverse(b.begin(), b.end());
	for (int i = 0; i < siz(t); i ++) {
		int ti = i, j = 0;
		for (; j < siz(b); j ++, ti ++) {
			if (b[j] == t[ti]) continue;
			else break;
		}
		string t1 = t + b.substr(j);
		// cout << t1 << endl;
		if (siz(ans) == 0) {
			ans = t1;
		} else if (siz(t1) < siz(ans)) {
			ans = t1;
		}
	}
	cout << ans;
}

// 测试
// test  tset
// out: test