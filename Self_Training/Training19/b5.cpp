#include <bits/stdc++.h>
#define debug(x) std::cout << x << "\n";
using i64 = long long;

const int N = 2e5 + 10;

std::unordered_map<std::string, int> idx;

int p[N], dist[N], dist2[N];

bool ok = true;

int sex[N], cnt;

inline int calc(std::string x) {
	if (idx.count(x)) {
		return idx[x];
	} else {
		idx[x] = ++ cnt;
		return cnt;
	}
}

bool check(int a, int b) {
	memset(dist, -1, sizeof dist);
	memset(dist2, -1, sizeof dist2);

	int c = a;
	dist[c] = 0;
	while (p[c] != -1) {
		if (p[c] == b) return false;
		dist[p[c]] = dist[c] + 1;
		c = p[c];
	}

	int c2 = b;
	dist2[c2] = 0;
	while (p[c2] != -1) {
		dist2[p[c2]] = dist2[c2] + 1;
		if (dist[p[c2]] != -1) {
			if (dist[p[c2]] >= 4 && dist2[p[c2]] >= 4) {
				return true;
			} else return false;
		}
		c2 = p[c2];
	}

	return true;
}

int main() {
	memset(p, -1, sizeof p);

	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::string a, b;

		std::cin >> a >> b;

		int len = b.size();

		char &c = b[len - 1];

		if (c == 'm' || c == 'f') {
			sex[calc(a)] = (c == 'm'?1:2);
			p[calc(a)] = calc(b.substr(0, len));
		} else {
			if (b.find("sson") != -1) {
				sex[calc(a)] = 1;
				p[calc(a)] = calc(b.substr(0, len - 4));
		 	} else if (b.find("sdottir") != -1)
		 		sex[calc(a)] = 2, p[calc(a)] = calc(b.substr(0, len - 7));
		}
	}

	int m;

	std::cin >> m;

	while (m --) {
		std::string a1, a2, b1, b2;
		
		std::cin >> a1 >> a2 >> b1 >> b2;

		if (!idx.count(a1) || !idx.count(b1)) {
			puts("NA");
			continue;
		}

		int k1 = sex[idx[a1]], k2 = sex[idx[b1]];

		ok = true;

		if (k1 == k2) puts("Whatever");
		else {
			ok = check(idx[a1], idx[b1]);
			puts(ok?"Yes":"No");
		}
	}
}