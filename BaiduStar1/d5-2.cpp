#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n, m;

vector<int> g[N];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int x, y;

		cin >> x >> y;

		// x -> y
		g[x].push_back(y);
	}
}