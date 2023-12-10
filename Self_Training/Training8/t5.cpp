#include <iostream>
#include <vector>

using i64 = long long;

const int N = 1e6 + 10;

int n;
int vis[N];
bool color[N];

std::vector<int> v[N];

void dfs(int x) {
	for(int i = 0; i < v[x].size(); i ++) {
		color[v[x][i]] = true;
		dfs(v[x][i]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
	bool check = false;
	std::cin >> n;

	for(int i = 1; i < n; i ++) {
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
	}

	int cnt1 = 0, cnt2 = 0;

	for(int i = 0; i < v[1].size(); i ++) {
		int &k = v[1][i];
		if(v[k].size()) {
			if(!check) dfs(k), check = true;
			cnt2 ++;
			vis[k] = 2;
		} else {
			cnt1 ++;
			vis[k] = 1;
		}
	}
	if(cnt1 % 2 != 0 && !cnt2) {
		std::cout << "NO";
		return 0;
	}

	int ct1 = 0, ct2 = 0;

	std::cout << "YES\n";


	// 默认子数节点为0，数上节点为1
	if(cnt1 % 2 == 0) {
		int op = 1;
		for(int i = 1; i <= n; i ++) {
			if(!vis[i]) {
				std::cout << 0;
			} else {
				if(vis[i] == 1) {
					std::cout << op;
					op = !op;
				} else {
					std::cout << 1;
				}
			}
			std::cout << " \n"[i == n];
		}
	} else {
		int op = 0;
		for(int i = 1; i <= n; i ++) {
			if(!vis[i]) {
				std::cout << (int)color[i];
			} else {
				if(vis[i] == 1) {
					std::cout << op;
					op = !op;
				} else {
					std::cout << 1;
				}
			}
			std::cout << " \n"[i == n];
		}
	}
}