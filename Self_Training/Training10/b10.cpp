#include <bits/stdc++.h>
#define ff first
#define ss second
using i64 = long long;

const int N = 1e5 + 10;

int n, k;
int h[N], w[N];

bool check(int x) {
	i64 cnt = 0;
	for(int i = 1; i <= n; i ++) {
    if(h[i] < x || w[i] < x) continue;
		cnt += ((i64)h[i] * w[i]) / ((i64)x * x);
	}
	return cnt >= k;
}


int main() {

	std::cin >> n >> k;

  	int bound = 0;

	for(int i = 1; i <= n; i ++) 
		std::cin >> h[i] >> w[i], bound = std::max(bound, std::max(h[i], w[i]));

	int l = 1, r = 100000;
	
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}

	std::cout << r;
}