#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;

vector<int> res;

map<string, vector<string>> a;
map<string, bool> v;
map<string, int> en;
vector<string> curr;


int n, m;

bool bfs() {
	int cal = 0;
	queue<string> q1;
	for(auto &i: curr) {
		if (!en[i]) q1.push(i), cal ++;
	}

	while (q1.size()) {
		string t = q1.front(); q1.pop();
		for (auto &x: a[t]) {
			if (!(--en[x])) {
				q1.push(x), cal ++;
			}
		}
	}

	return cal == n;
}

int main() {
	cin >> m;
	for (int i = 1; i <= m; i ++) {
		string x, y; cin >> x >> y;
		if(!v[x]) n ++, v[x] = 1, curr.push_back(x);
		if(!v[y]) n ++, v[y] = 1, curr.push_back(y);
		a[x].push_back(y);
		en[y] ++;
	}
    if (!bfs()) {
    	cout << "No";
    } else {
    	cout << "Yes";
    }
}