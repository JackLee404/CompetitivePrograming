#include <bits/stdc++.h>

using i64 = long long;

int dx[] = {0, 1, -1}, dy[] = {1, 0, 0};


void solve() {
	int m;
	std::string a[2];
	std::cin >> m >> a[0] >> a[1];

	int r = -1, l;
	for(int i = 0; i < m; i ++) {
		if(a[0][i] != a[1][i]) {
			if(r == -1) l = i;
			r = i;
		}
	}

	if(r == -1) {
		puts("YES");
		return;
	}

	bool st1, st2;

	st1 = st2 = true;

	int jpos = -1;
	for(int i = l; i <= r; i ++) {
		if(a[0][i] == 'W') {
			if(jpos == -1) jpos = 1;
			else {
				if(jpos == 0) {
					st1 = false;
					break;
				}
			}
		} else if(a[1][i] == 'W') {
			if(jpos == -1) jpos = 0;
			else {
				if(jpos == 1) {
					st1 = false;
					break;
				}
			}
		} else {
			if(jpos != -1) {
				jpos = !jpos;
			}	
		}
	}
	puts(st1?"YES":"NO");
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}