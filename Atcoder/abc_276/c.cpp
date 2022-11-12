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
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

vector<vector<int>> al;

vector<int> t;

int n, a[200], b[200];

bool st[500];

// void dfs(int u) {
// 	if (u == n) {
// 		al.push_back(t);	
// 		for (auto &v: t) {
// 			cout << " " << v;
// 		}	
// 		cout << endl;
// 		return;
// 	}
// 	for (int i = 0; i < n; i ++) {
// 		if (!st[i]) {
// 			st[i] = true;
// 			t.push_back(a[i]);
// 			dfs(u + 1);
// 			t.pop_back();
// 			st[i] = false;
// 		}
// 	}
// }

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		b[i] = a[i];
	}

	int flag; 	
	for (int i = n - 1; i > 0; i --) {
		if (a[i] < a[i - 1]) {
			flag = i - 1;
			break;		
		}
	}
	int mi1 = 0x3f3f3f3f, flag2 = 0;
	for (int i = flag; i < n; i ++) {
		if (a[i] < a[flag] && a[flag] - a[i] < mi1) {
			mi1 = a[flag] - a[i];
			flag2 = i;
		}	
	}
	swap(a[flag], a[flag2]);
	sort(a + flag + 1, a + n, greater<int>());
	cout << a[0];
	for (int i = 1; i < n; i ++) {
		cout << " " << a[i];
	}
	// dfs(0);
}