#include <iostream>
#include <map>
#include <cstring>

const int N = 10;

int a[N][N];
bool vis[N][N], d[N];
std::map<int, int> mp;
int n;

bool check(int u, int st) {
	bool ok = true;

	for(int j = 0; j < n; j ++) {
		int k = st >> j & 1, c = j + 1;

		if(k) {
			if(!a[u][c]) return false;
			if(!ok) return false;
			if(d[c]) return false;
			ok = false;
		}

		if(!a[u][c]) ok = true;
	}
	
	return true;
}

int count(int u, int st) {
	int res = 0;
	for(int i = 0; i < n; i ++) {
		if(st >> i & 1) {
			res ++;
			d[i + 1] = true;
		}
	}
	return res;
}

int ans;

void dfs(int u) {
	if(u == n + 1) {
		mp[ans] ++;
		return;
	}

	for(int i = 1; i <= n; i ++) {
		if(!a[u][i]) {
			// 如果当前是洞代表上面的车的影响没了
			d[i] = false;
		}
	}
	
	bool tmp[N];	
	memcpy(tmp, d, sizeof tmp);


	for(int i = 0; i < (1 << n); i ++) {
		if(check(u, i)) {
			int k = count(u, i);
			ans += k;
			dfs(u + 1);
			ans -= k;	
			memcpy(d, tmp, sizeof tmp);
		}
	}
}

int main() {
	

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			std::cin >> a[i][j];
		}
	}

	dfs(1);

	for(int i = 1; i <= n * n; i ++) {
		if(!mp[i]) break;
		std::cout << mp[i] << "\n";	
	}
}