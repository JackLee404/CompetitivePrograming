#include <bits/stdc++.h>

using i64 = long long;

const int N = 100;

int postorder[N], midorder[N];
std::unordered_map<int, int> l, r, pos;

int build(int ml, int mr, int pl, int pr) {

	int root = postorder[mr];
	int k = pos[root];

	if(ml < k) l[root] = build(ml, k - 1, pl, pl + (k - 1 - ml));
	if(mr > k) r[root] = build(k + 1, mr, pl + (k - 1 - ml) + 1, pr - 1);

	return root;
}

void bfs(int root) {
	std::queue<int> q1;
	q1.push(root);

	while(q1.size()) {
		int t = q1.front();

		if(l.count(t)) q1.push(l[t]);
		if(r.count(t)) q1.push(r[t]);

		std::cout << t << " ";
	}
}


int main() {
	int n;

	std::cin >> n;

	for(int i = 0; i < n; i ++) {
		std::cin >> postorder[i];
	}

	for(int i = 0; i < n; i ++) {
		std::cin >> midorder[i];
		pos[midorder[i]] = i;
	}

	int root = build(0, n, 0, n);
}