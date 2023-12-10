#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF 0x3f3f3f3f
typedef std::pair<int, int> PII;
using i64 = long long;

const int N = 1e4 + 10, M = 2e6 + 10;

int n, m, cnt;

int p[M], count[M], type[N];

std::unordered_map<std::string, int> idx;

std::vector<int> g[N];

bool st[N];

int tot, lazytag[N];

int getid(std::string t) {
	if (!idx.count(t)) {
		return idx[t] = ++ cnt;	
	}
	return idx[t];
}

bool isnumber(std::string t) {
	for (auto x: t) {
		if (!isdigit(x)) return false;
	}
	return true;
}

void dfs(int u) {
	if (lazytag[u]) return;
	
	tot += type[u];

	// std::cout << u << "\n";
	
	for (auto x: g[u]) {
		if (!st[x]) {
			st[x] = true;
			dfs(x);
		}
	}
}

int main() {
	std::cin >> n >> m;

	while (m --) {
		std::string t1, t2;

		std::cin >> t1 >> t2;

		int k1 = getid(t1), k2 = getid(t2);

		g[k2].push_back(k1);

		if (isnumber(t1)) {
			type[k1] = 1;
		}
	}

	std::string act;

	while (true) {
		std::cin >> act;

		std::string t1, t2;

		if (act == "E") break;

		if (act == "T") {
			std::cin >> t1 >> t2;

			// 懒删除并获取新的id
			lazytag[getid(t1)] = 1;
			idx[t1] = ++ cnt;

			type[cnt] = 1;
			g[getid(t2)].push_back(cnt);
			
		} else {
			memset(st, 0, sizeof st);
			tot = 0;

			std::cin >> t1;
			
			st[getid(t1)] = true;	
			dfs(getid(t1));

			std::cout << tot << "\n";
		}
	}	
}