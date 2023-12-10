#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
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
int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

const int N = 200;

int n, m, dep[N][N], cnt, tot;
char a[200][200];

int bfs(PII p1, PII p2) {
	memset(dep, 0, sizeof dep);
	queue<PII> q1;
	int ans = 0, cnt1 = 0;

	q1.push(p1), q1.push(p2);
	
	dep[p1.f][p1.s] = dep[p2.f][p2.s] = 1;

	if (p1 != p2) cnt1 = 2;
	else cnt1 = 1;

	while (q1.size()) {
		PII t = q1.front(); q1.pop();
		
		int tx = t.f, ty = t.s;
		
		ans = max(ans, dep[tx][ty]);
		// cout << tx << " " << ty <<":"<<dep[tx][ty] << endl;
		for (int i = 0; i <= 3; i ++) {
			int x = tx + dx[i], y = ty + dy[i];
			// cout << x << " " << y << " " << dx[i] << " " << dy[i] << endl;
			if (x <= n && x >= 1 && y <= m && y >= 1 && a[x][y] == '#' && !dep[x][y]) {
				dep[x][y] = dep[tx][ty] + 1;
				q1.push({x, y});
				cnt1 ++;
			}
		}
	}
	return cnt1 == tot?ans-1:INF;
}

int main() {
	// for (int i = 0; i <= 3; i ++) {
	// 	cout << dx[i] << " " << dy[i] << endl;
	// }
	vector<PII> p1;
	int _; cin >> _;
	while (_ --) {
		int ans = INF;
		cin >> n >> m; 

		p1.clear(), tot = 0;

		rep (i, 1, n) {
			rep (j, 1, m) {
				cin >> a[i][j];
				if (a[i][j] == '#') p1.push_back(make_pair(i, j)), tot ++;
			}
		}


		// cout << bfs({2, 2}, {2, 2}) << endl;	
		rep (i, 0, siz(p1) - 1) {
			rep (j, 0, siz(p1) - 1) {
				ans = min(bfs(p1[i], p1[j]), ans);
			}
		}

		printf("Case %d: %d\n", ++cnt, ans==INF?-1:ans);
	}
}