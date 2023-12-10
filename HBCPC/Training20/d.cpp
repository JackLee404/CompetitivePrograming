#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<string>> v;

vector<string> res;

// vector<string> g[N];

unordered_map<string, int> en;

map<string, vector<string>> g;

void bfs() {
	queue<string> q1;
	for (auto &x: en) {
		// cout << x.first << " " << x.second << endl;
		if (!x.second) {
			q1.push(x.first);
		}
	}
	while (q1.size()) {
		// cout << "?" << endl;
		string t = q1.front(); q1.pop();
		res.push_back(t);
		sort(g[t].begin(), g[t].end());
		for (auto &x: g[t]) {
			if (!--en[x]) {
				q1.push(x);
			}
		}
	}
}

int main() {
	int n; cin >> n;

	auto act = [](vector<string> &a, vector<string> &b) {
        // cout << a.size() << " " << b.size() << endl;
		if (a.size() != b.size()) return;
		for (int i = 0; i < a.size(); i ++) {
			if (a[i] == b[i]) continue;
			g[a[i]].push_back(b[i]);
			en[b[i]] ++;
			break;
		}
	};

	auto init = [](string &b) {
		vector<string> t;
		string s1;
		for (int i = 0; i < b.size(); i ++) {
			if (b[i] == '.') {
				t.push_back(s1);
                if (!en.count(s1)) en[s1] = 0;
                s1.clear();
			} else {
				s1.push_back(b[i]);
			}
		}
        if (s1.size()) {
        	
        	if (!en.count(s1)) en[s1] = 0;
        	t.push_back(s1);
        }
		v.push_back(t);
	};

	for (int i = 1; i <= n; i ++) {
		string t; cin >> t;	
		init(t);
		if (i != 1) {
			int k = v.size();
			act(v[k - 2], v[k - 1]);
		}
	}
    
    bfs();

	for (int i = 0; i < res.size(); i ++) {
		cout << res[i] << ".\0"[i == (int) res.size() - 1];
	}
}