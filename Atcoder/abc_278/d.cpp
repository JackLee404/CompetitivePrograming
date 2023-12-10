#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <algorithm>
#include <cstring>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define siz(v) ((int) v.size())
#define judge(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define mahaton(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))
using namespace std;

const int N = 2e5 + 10;

typedef pair<int, int> PII;
typedef long long LL;

LL c[N], tag;

bool change[N];

int main() {
	int n, q;
	LL change_value = 0;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> c[i];
		change[i] = true;
	}
	cin >> q;
	while (q --) {
		int t, a, b;
		cin >> t;
		if (t == 1) {
			cin >> a;
			memset(change, 0, sizeof change);
			change_value = a;
		} else if (t == 2) {
			cin >> a >> b;			
			if (!change[a - 1])
				change[a - 1] = true, c[a - 1] = change_value;
			c[a - 1] += b;		
		} else {
			cin >> a;
			if (!change[a - 1])
				change[a - 1] = true, c[a - 1] = change_value;
				cout << c[a - 1] << endl;
		}
	}
}