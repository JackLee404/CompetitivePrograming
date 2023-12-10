#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <algorithm>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define siz(v) ((int) v.size())
#define judge(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define mahaton(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))
using namespace std;

typedef pair<int, int> PII;

int main() {
	queue<int> q1;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i ++) {
		int c;
		cin >> c;
		q1.push(c);
	}

	for (int i = 0; i < k; i ++) {
		q1.pop();
		q1.push(0);
	}

	while (q1.size()) {
		cout << q1.front() << " ";
		q1.pop();
	}
}