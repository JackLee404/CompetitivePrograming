#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#define INF 0x3f3f3f3f
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
// typedef long long LL;
// typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
// typedef priority_queue<int> B_HEAP;
// typedef pair<string, int> PSI;
// typedef pair<int, int> PII;
const int N = 1e5 + 10;

int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

int d[N];
	
bool state[N];
int n, k;

void bfs(int u) {
	memset(d, -1, sizeof d);
	queue<int> q1;
	q1.push(u);
	d[u] = 0;
	while (q1.size()) {
		int t = q1.front(); q1.pop();
		int np;
		if (t == k) {
			return;	
		}
		rep (i, 0, 2) {
			if (i == 0) np = t * 2;
			else if (i == 1)np = t + 1;
			else np = t - 1;
			if (np >= 0 && np <= 1e5 && d[np] == -1) {
				state[np] = true;
				q1.push(np);	
				d[np] = d[t] + 1;
			}	
		}
	}
}



int main() {
	cin >> n >> k;
	bfs(n);
	cout << d[k] << endl;
}