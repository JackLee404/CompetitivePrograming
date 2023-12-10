#include <bits/stdc++.h>
#define pii std::pair<int, int>
#define ff first
#define ss second
using i64 = long long;

const int N = 1e5 + 10;

struct node {
	int id, a, b;
};

int a[N], dp[N], stk[N];

pii b[N];

bool cmp(pii a, pii b) {
	return (a.ff - a.ss) > (b.ff - b.ss);
}

void solve() {
	int n;
	
	std::cin >> n;
	
	std::vector<node> v1;
	
	for (int i = 1; i <= n; i ++) {
		int c, d;
		
		std::cin >> c >> d;
		
		b[i] = {c, d};
	}
	
	int ans = 0, l = 0, r = 0;
	
	stk[0] = -1e9;
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		
		dp[i] = 1;
	
		for (int j = 1; j <= i - 1; j ++) {
			while (l < r) {
				int mid = l + r >> 1;
				if (cmp(b[a[l]], b[a[mid]])) r = mid;
				else l = mid + 1;
			}
		}
		
		if (cmp(b[a[mid]], b[a[l]])) r ++;
		
		stk[l] = a[l];
		
		ans = std::max(dp[i], ans);
	}
	
	std::cout << n - l << "\n";
}

int main() {
	int _;
	
	std::cin >> _;
	
	while (_ --) {
		solve();
	}
}
