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

LL ans;
vector<int> a[N];
int b[N];
bool ok;

int st, ed;

void add(int b, int c) {
	a[b].push_back(c);
}

int dfs(int p) {
	if (a[p].size() == 0 && p != ed) {
		ok = false;
		return 0;
	} else if (p == ed) {
		return 1;
	}

	if (b[p] != -1) {
		return b[p];
	}

	b[p] = 0;

	for (auto &x: a[p]) {
		b[p] += dfs(x);
	}

	return b[p];
}

int main() {
	memset(b, -1, sizeof b);
    ok = true;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m + 1; i ++) {
		int b, c; cin >> b >> c;
		if (i == m + 1) {
			st = b, ed = c;
		} else {
			add(b, c);
		}
	}
//     cout << st << " " << ed << endl;
	dfs(st);
	cout << b[st] << " " << (ok?"Yes":"No");
}