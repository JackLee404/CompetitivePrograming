#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define siz(x) (int)x.size()
#define IOS ios::sync_with_stdio(false);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define dbg1(a) cout << a << endl;
#define dbg2(a, b) cout << a << " " <<  b << endl;
#define dbg3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

int v[300][300], arr[300], vis[300], mi, mc = INF, ct = 0;

int n, m;

int add(int a, int b) {
	if (a != -1 && b != -1) {
		return a + b;
	} else {
		return -1;
	}
}

void solve(int k1) {
	memset(vis, 0, sizeof vis);
	bool ok = true;
	int n1, cost = 0, cnt = 0;
	vector<int> a;
	cin >> n1;
	a.push_back(0);
	for (int i = 1; i <= n; i ++){
		int t; 
		cin >> t;
		a.push_back(t);
	}
	a.push_back(0);
	for (int i = 0; i < a.size(); i ++) {
		if (a[i] == 0 && vis[a[i]] == 2) {
			return;
		} else if (a[i] != 0 && vis[a[i]]) {
            return;
        }
		vis[a[i]] ++;
		if (i >= 1) {
			if (add(cost, v[a[i - 1]][a[i]]) == -1) {
				return;
			}
			cost = add(cost, v[a[i - 1]][a[i]]);
		}
		if (a[i] != 0)
		cnt ++;
	}
    if (cnt == n) {
        if (cost < mc) {
            mi = k1;
            mc = cost;
        }
        ct ++;
    }
}

int main() {
	int cnt = 0, mcost = INF, mi;
	cin >> n >> m;
	memset(v, -1, sizeof v);
	for (int i = 1; i <= m; i ++) {
		int a, b, c; 
		cin >> a >> b >> c;
		v[a][b] = c, v[b][a] = c;
	}
	int q; cin >> q;
	vector<int> b;
	for (int k = 1; k <= q; k ++) {
		solve(k);
	}
	cout << ct << "\n";
	cout << mi << " " << mc;
}