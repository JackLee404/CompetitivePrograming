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
const int N = 1e5 + 10;

/*
	构造一个数组满足以下性质:
		每个数都不为0
		相邻两个数的和为整个数组的和
*/


void solve() {
	int n; cin >> n;
	if (n % 2 != 0) {
		if (n < 5)
			cout << "NO\n";
		else {	
			cout << "YES\n";
			for (int i = 1; i <= n; i ++) {
				if (i % 2) cout << n / 2 - 1;
				else cout << - n / 2;
				cout << " \n"[i == n];
			}
		}
	} else {
		cout << "YES\n";	
		for (int i = 1; i <= n; i ++) {
			if (i % 2) cout << 10;
			else cout << -10;
			if (i != n) cout << " ";
		}
		cout << "\n";
	}
}


int main() {
	int _;
	cin >> _;
	while (_ --) {
		solve();
	}
}