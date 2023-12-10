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

char out[3] = {"Red Alert!!", "Yellow Alert!", "Green ^_^"};

int main() {
	int a, b; cin >> a >> b;
	if (a < 60) {
		if (b < 30) cout<<out[0];
		else if (b < 60) cout<<out[1];
		else if (b <= 100) cout<<out[2];
	} else if (a < 80) {
		if (b < 50) cout<<out[0];
		else if (b < 70) cout<<out[1];
		else if (b <= 100) cout<<out[2];
	} else if (a <= 200) {
		if (b < 60) cout<<out[0];
		else if (b < 75) cout<<out[1];
		else if (b <= 100) cout<<out[2];
	}
}