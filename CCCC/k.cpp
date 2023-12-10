#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 10;

int n, c;

struct node {
	std::string sc;
	int peo;
	
	bool operator<(const node &t) const {
		return peo < t.peo;
	}
};


std::priority_queue<node> h1;

int cnt;

int b[N];

std::unordered_map<std::string, int> mp;

int main() {
	std::cin >> n >> c;
	
	std::vector<std::string> v2;

	
	for (int i = 1; i <= n; i ++) {
		std::string sc;
		int peo;
		
		std::cin >> sc >> peo;
		
		h1.push({sc, peo});
		
		v2.push_back(sc);
	}

	while (h1.size()) {
		node t = h1.top(); h1.pop();
		
		if (t.peo >= c) {
			t.peo -= c;
			b[++cnt] = c;
			mp[t.sc] ++;
			if (t.peo) h1.push({t});
		} else if (t.peo < c) {
			bool ok = false;
			for (int i = 1; i <= cnt; i ++) {
				if (c - b[i] >= t.peo) {
					ok = true;
					b[i] += t.peo;
				}
			}
			if (!ok) {
				b[++ cnt] = t.peo;
				mp[t.sc] ++;
			}
 		}
	}
	for (int i = 0; i < v2.size(); i ++) {
		std::cout << v2[i] << " " << mp[v2[i]] << "\n";
	}
}