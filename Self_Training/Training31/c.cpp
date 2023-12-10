#include <iostream>
#include <unordered_map>

using i64 = long long;

const int N = 100;

int n, m, h, k;

std::string act;

std::unordered_map<int, bool> hash;

int get(int x, int y) {
	return (x + 1) * 1e5 + y;
}

int dx[300], dy[300];

int main() {
	dx[(int)'R'] = 1, dy[(int)'R'] = 0;
	dx[(int)'L'] = -1, dy[(int)'L'] = 0;
	dx[(int)'U'] = 0, dy[(int)'U'] = 1;
	dx[(int)'D'] = 0, dy[(int)'D'] = -1;

	std::cin >> n >> m >> h >> k;

	std::cin >> act;

	for (int i = 1; i <= m; i ++) {
		int x, y;

		std::cin >> x >> y;

		hash[get(x, y)] = true;
	}

	bool ok = true;


	int nx, ny, health = h;

	nx = ny = 0;

	// if (hash[get(nx, ny)] && health >= 0 && health < k) {
	// 	health = k;
	// }

	for (int i = 0; i < (int) act.size(); i ++) {
		nx += dx[(int) act[i]], ny += dy[(int) act[i]];

		health --;

		if (hash[get(nx, ny)] && health >= 0 && health < k) {
			hash[get(nx, ny)] = false;
			health = k;
		}

		// std::cout << health << "\n";

		if (health < 0) {
			ok = false;
			break;
		}
	}

	puts(ok?"Yes":"No");
}