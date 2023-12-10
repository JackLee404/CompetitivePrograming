#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i ++) {
		int t; cin >> t, q.push(t);
	}
	while (k --) {
		int cnt = 1;
		bool ok = true;
		queue<int> q1(q); deque<int> d1; vector<int> out(n + 1);
		for (int i = 1; i <= n; i ++) {
			cin >> out[i];
		}
		for (int i = 1; i <= n; i ++){
			if (d1.size() && (d1.front() == out[i] || d1.back() == out[i])) {
				if (d1.front() == out[i]) {
					d1.pop_front();
				} else d1.pop_back();
				continue;
			}
			while (q1.size() && q1.front() != out[i]) {
				d1.push_back(q1.front()); q1.pop();
			}
			if (q1.size()) {
// 				cout << q1.front() << " ";
				q1.pop();
			} else {
				ok = false;
			}
		}
		puts(ok?"yes":"no");
	}
}