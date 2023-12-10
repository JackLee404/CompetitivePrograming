#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10;

string ex = "ATCG";

int n, deep, pos[N], ans;

vector<string> a;

string now;

bool flag;


int cal(int pos[]) {
	int mx = 0;
	for (int i = 0; i < a.size(); i ++) {
		int len = (int) a[i].length();
		mx = max(mx, len - pos[i]);
	}
	return mx;
}

void dfs(int u, int pos[]) {

	if (u > deep) return;
	// cout << u << endl;
	if (flag) return;
	
	int mx = cal(pos);

	if (u + mx > deep || !mx) {
		if (!mx) ans = u;
		return;
	}

	int t[N];

	for (int i = 0; i <= 3; i ++) {	
		bool check = false;
		for (int j = 0; j < a.size(); j ++) {
			t[j] = pos[j];
			if (pos[j] < a[j].size() && ex[i] == a[j][pos[j]]) {
				t[j] = pos[j] + 1;
				check = true;
			}
		}
		if (check) dfs(u + 1, t);
		if (flag) return;
	}
}


int main() {
	string t;
	int _;
	cin >> _;
	while (_ --) {
		deep = 0;
		a.clear();
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> t;
			a.push_back(t);
			deep = max(deep, (int) t.size());
		}

		ans = -1;

		while(true) {
			memset(pos, 0, sizeof pos);
			dfs(0, pos);
			if (ans != -1) {
				cout << ans << endl;
				break;
			}
			deep ++;
		}
	}
}