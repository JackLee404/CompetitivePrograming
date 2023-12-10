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

const int N = 2600;

int dx[]{0, 1, -1, 0}, dy[]{1, 0, 0, -1};


bool vis[N];


void solve() {
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	int l = 1, r = n * n, t = 0;
	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) {
			if(t) v[i][j] = l ++;
			else v[i][j] = r --;
			t ^= 1;
		}
		if(i & 1) reverse(v[i].begin(), v[i].end());
	}
	rep(i, 0, n - 1) rep(j, 0, n - 1) cout << v[i][j] << " \n"[j == n - 1];
}


int main() {
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}
