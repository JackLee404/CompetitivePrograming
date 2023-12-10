#include <iostream>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e3 + 5;

int diff[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
	diff[x1][y1] += c, diff[x1][y2 + 1] -= c, diff[x2 + 1][y1] -= c, diff[x2 + 1][y2 + 1] += c;
}

int main() {
	int n, m, q, a[N][N]; cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
		cin >> a[i][j], insert(i, j, i, j, a[i][j]);
	}
	while(q --) {
		int x1, y1, x2, y2, c; cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);	
	}
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++)
		cout << (diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1]) << "\0 \n "[2 * (i != n) + (j != m)];
}