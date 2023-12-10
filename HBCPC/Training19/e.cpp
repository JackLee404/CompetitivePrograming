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

int n, a[N], b[N], cnt;

void dfs(int u) {
	if (u > n)
		return;

	dfs (u * 2);
	dfs (u * 2 + 1);
	b[u] = a[cnt ++];
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	dfs(1);
	
	for (int i = 1; i <= n; i ++) {
		cout << b[i] <<  " \n"[i == n];	
	}
}