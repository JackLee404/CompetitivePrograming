#include <bits/stdc++.h>

using namespace std;

int n, sex[510], d[510][510];

struct node{
	int id, val;
};

void floyd() {
	for (int k = 1; k <= n; k ++){
		for (int i = 1; i <= n; i ++){
			for (int j = 1; j <= n; j ++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	memset(d, 0x3f, sizeof d);
	cin >> n;
    for (int i = 1; i <= n; i ++) d[i][i] = 0;
	for (int i = 1; i <= n; i ++) {
		string t; cin >> t; sex[i] = (t == "M");
		int k; cin >> k;
		for (int j = 1; j <= k; j ++){
			int a, b; scanf("%d:%d", &a, &b);
			d[i][a] = b;
		}
        cout << sex[i] << endl;
	}
	
	floyd();

	vector<node> v1, v2;

	for (int i = 1; i <= n; i ++) {
		int mx = 0x3f3f3f3f;
		for (int j = 1; j <= n; j ++) {
			if (i != j && sex[i] != sex[j]) {
				mx = min(mx, d[j][i]);
			}
		}
		if (sex[i]) v1.push_back({i, mx});
		else v2.push_back({i, mx});
	}
    
	auto cmp = [](node &a, node &b) {
		if (a.val == b.val) return a.id < b.id;
		else return a.val < b.val;
	};

	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);

	for (int i = 0; i < v2.size(); i ++){
		if (i) {
			if (v2[i].val != v2[i - 1].val) break;
			cout << " " << v2[i].id;
		} else {
			cout << v2[i].id;
		}
	}
	cout << "\n";
	for (int i = 0; i < v1.size(); i ++){
		if (i) {
			if (v1[i].val != v1[i - 1].val) break;
			cout << " " << v1[i].id;
		} else {
			cout << v1[i].id;
		}
	}
    cout << "\n";
    for (auto &x: v2) {
        cout << x.id << " " << x.val << endl;
    }
}