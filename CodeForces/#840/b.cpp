#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
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
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

struct node{
	int f, s;
};


bool operator < (node a, node b) {
	return a.s > b.s;
}



void solve() {
	priority_queue<node> heap;
	int n, k, tag = 0;
	cin >> n >> k;
	vector<node> a(n);
	for (auto &x: a) {
		cin >> x.f;
	}
	for (auto &x: a) {
		cin >> x.s;
	}
	for (auto &x: a) {
		heap.push(x);
	}
	while (heap.size()) {
		// cout << k << endl;
		// cout << heap.top().f << " " << heap.top().s << endl;
		tag -= k;
		// cout << tag << endl;
		while (heap.size() && heap.top().f  + tag <= 0) {
			heap.pop();
		}
		if (heap.size())
			k -= heap.top().s;
		if (k <= 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}


int main() {
	IOS
	int _;
	cin >> _;
	while (_ --) {
		solve();	
	}
}