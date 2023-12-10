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


const int N = 2e5 + 10;

int n, q;

map<int, set<int>> mp;

int main() {
	cin >> n >> q;

	for (int i = 0; i < q; i ++) {
		int t, c, d;
		cin >> t >> c >> d;
		if (t == 1) {
			mp[c].insert(d);
		} else if (t == 2) {
			mp[c].erase(d);
		} else if (t == 3) {
			if (mp[c].find(d) != mp[c].end() && mp[d].find(c) != mp[d].end()) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}

}