#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
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
using i64 = long long;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;

const int N = 2600;

// case1: ni为0 xi为1 输出-1
// case3: ni为0 xi为0 什么都不需要
// case4: ni为1 xi为0 找到最小的数使该位变成0
// case2: ni为1 xi为1 找到最大的数使该位不变 和当前区间取交集

void solve() {
	i64 n, x; cin >> n >> x;
	vector<i64> f(64);	
	i64 l = n, r = 3e18;
	for(int i = 0; i < 64; i ++) {
		i64 k1 = (n >> i) & 1,  k2 = (x >> i) & 1;
		if(!k1 && k2) {
			puts("-1");
			return;
		} else if(k1 && !k2) {
			l = max(l, ((n / (1ll<<i) + 1)) * (1ll<<i));
		} else if(k1 && k2) {
			r = min(r, ((n / (1ll<<i)) + 1) * (1ll<<i) - 1);
		}
	}
	if(l <= r) {
		cout << l << "\n";
	} else {
		puts("-1");
	}
}

int main() {
	int _; cin >> _;
	while(_ --) {
		solve();
	}
}