#include <bits/stdc++.h>
#define f first
#define s second
#define rep(i, j, k) for (int i = j; i <= k; i ++)
using namespace std;
typedef pair<int, int> PII;
const int mod = 1e9 + 7, N = 300;

int p[N], rel[N][N];

int find(int x) {
	if (x != p[x]) x = find(p[x]);
	return x;
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	rep (i, 1, n) p[i] = i;
	while (m --) {
		int a, b, c; cin >> a >> b >> c;
		if (c == -1) rel[a][b] = 1, rel[b][a] = 1;
		else {
			p[find(a)] = p[find(b)];
		}
	}
	while (k --) {
		int a, b;
		cin >> a >> b;
		if (rel[a][b] == -1 || rel[b][a] == -1) {
			puts("No way");
		} else if (find(a) == find(b)) {
			puts("OK");
		} else {
			puts("OK but...");
		}
	}
}