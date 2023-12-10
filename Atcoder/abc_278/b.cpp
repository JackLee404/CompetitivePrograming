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

bool check(int a, int b) {
	if (a <= 23 && a >= 0 && b <= 59 && b >= 0)
		return true;
	else
		return false;
}

bool check2(int a, int b) {
	int na, nb;
	nb = (a % 10) * 10 + b % 10;
	na = (a / 10) * 10 + b / 10;
	// cout << na << " " << nb << endl;
	return check(na, nb);
}

int main() {
	int a, b;
	cin >> a >> b;

	check2(19, 57);
	while (true) {
		if (check2(a, b)) {
			cout << a << " " << b << endl;
			break;
		}
		if (b + 1 == 60) {
			a ++;
			b = 0;
		} else b ++;
	}
}