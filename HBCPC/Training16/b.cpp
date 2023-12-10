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

int main() {
	LL n, ans[20], sum[20];
	cin >> n;
	rep (i, 1, n) {
		LL c;
		cin >> c;
		if (i != 1) {
			ans[i] = c - sum[i - 1];
			sum[i] = ans[i] + sum[i - 1];
		} else {
			ans[i] = c;
			sum[i] = c;
		}
	}

	rep (i, 1, n) {
		cout << ans[i];
		if (i != n) cout << " ";
	}
}