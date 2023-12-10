#include <bits/stdc++.h>
#define siz(x) (int)x.size()
using i64 = long long;

const int N = 25;


std::vector<std::string> v1;

int n, tot = 1;
int vis[N], bk;
std::string ans;

bool check(std::string &t1, int y) {
	int pos = siz(t1) - 1;
	char fs = v1[y][0];
	while(pos >= 0 && t1[pos] != fs) {
		pos --;
	}

	if(pos == -1 || siz(t1) - pos > siz(v1[y])) return false;

	int j = 0;
	for(int i = pos; i < siz(t1); i ++, j ++) {
		if(t1[i] != v1[y][j]) {
			return false;
		}
	}

	std::string t = t1.substr(0, pos) + v1[y];

	t1 = t;
	return true;
}

void dfs(){
	tot = std::max(tot, siz(ans));
	
	for(int i = 0; i < n; i ++) {
		if(vis[i] < 2) {
			std::string tmp = ans;
			int bk2 = bk;
			int st = -1;
			// if(bk != -1) st = v1[bk].find(v1[i]);

			if(!check(ans, i)) {
				continue;
			}
			vis[i] ++;
			bk = i;
			dfs();
			bk = bk2;
			ans = tmp;
			vis[i] --;
		}
	}

	// std::cout << ans << "\n";
	
}

int main() {
	// {
	// 	// test
	// 	v1.push_back("astonish");

	// 	std::string t = "beast";

	// 	std::cout << check(t, 0);

	// 	std::cout << t << "\n";

	// 	// std::cout << check(1, 0);
	// }

	std::cin >> n;

	v1.resize(n);

	for(int i = 0; i < n; i ++) {
		std::cin >> v1[i];
	}

	std::cin >> ans;

	bk == -1;

	dfs();

	std::cout << tot;
}