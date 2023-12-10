#include <iostream>
#include <set>
using namespace std;

const int N = 1e4 + 10;

set<int> s1[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int m; cin >> m;
		for (int j = 1; j <= m; j ++) {
			int t; cin >> t;
			s1[i].insert(t);
		}
	}
	int q; cin >> q;
	while (q --) {
		int a, b, n1, n2; cin >> a >> b;
		n1 = n2 = 0;
		for (auto x: s1[a]) {
			if (s1[b].find(x) != s1[b].end()) {
				n1 ++, n2 --;
			} else n2 ++;
		}
		n2 += s1[b].size();
		printf("%.2f%", n1 * 1.0 / n2);
	}
}