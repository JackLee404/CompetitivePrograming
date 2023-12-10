#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using namespace std;

const int N = 550;

int n;

int d[N][N], sex[N];

void floyd() {
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	cin >> n;

	rep(i, 1, n)
		rep(j, 1, n)
			d[i][j] = (i == j?0:INF);

	rep (i, 1, n) {
		int a, b, k;
		string t;
		cin >> t >> k;
		sex[i] = (t == "F"?0 :1);
		rep (j, 1, k) {
			scanf("%d:%d", &a, &b);
			d[i][a] = min(d[i][a], b);
		}
	}

	floyd();

	vector<pair<double, int>> fx, mx;

	// auto cmp = [](auto a, auto b) {
	// 	return a.f > b.f;
	// };

	rep (i, 1, n) {
		int md = -1;
		rep (j, 1, n) {
			if (sex[i] == sex[j]) continue;
			md = max(md, d[i][j]);
		}
		if (!sex[i]) fx.push_back({md, i});
		else mx.push_back({md, i});
	}
	
	sort(fx.begin(), fx.end());
	sort(mx.begin(), mx.end());

	// for (auto& v: fx) {
	// 	cout << v.f << " " << v.s << endl;
	// }
	
	for (int i = 0; i < fx.size(); i ++) {
		if (!i) cout << fx[i].s;
		else if (fx[i].f == fx[i - 1].f) cout << " " << fx[i].s;
		else break;
	}
	cout << endl;
	for (int i = 0; i < mx.size(); i ++) {
		if (!i) cout << mx[i].s;
		else if (mx[i].f == mx[i - 1].f) cout << " " << mx[i].s;
		else break;
	}
}