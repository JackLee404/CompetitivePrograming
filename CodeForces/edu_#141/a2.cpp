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

void solve() {
	string t; cin >> t;
	int n = t.size();

	int pos = 0;
	for(int i = 1; i < n - 1; i ++) {
		if(t[i] == 'a') {
			pos = i;
			break;
		}
	}
	if(pos) {
		cout << t.substr(0, pos) << " a " << t.substr(pos + 1, n - pos);
	} else {
		cout << t[0] << " " << t.substr(1, n - 2) << " " << t[n - 1];
	}
	cout<<"\n";
}

int main() {
	int _; cin >> _;
	while(_ --) {
		solve();
	}
}