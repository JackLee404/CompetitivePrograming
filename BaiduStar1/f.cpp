#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	queue<int> q1;

	for (int i = 1; i <= n; i ++) q1.push(i);

	for (int i = 1; ; i ++) {
		if (q1.empty()) break;
		else if (i % m == 0) {
			cout << q1.front() << " ";
			q1.pop();
		} else {
			q1.push(q1.front());
			q1.pop();
		}
	}
}