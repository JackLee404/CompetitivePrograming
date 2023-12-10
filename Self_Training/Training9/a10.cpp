#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using i64 = long long;

const int N = 2e3 + 100;

int m, n, k, l, d;

std::map<int, int> mp1;

std::map<int, int> mp2;

bool vis[N], vis2[N];


int main() {
	std::cin >> m >> n >> k >> l >> d;

	std::vector<int> a1, a2, a3, a4;

	for(int i = 1; i <= d; i ++) {
		int x1, y1, x2, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2) {
			int k = std::min(y1, y2);
			mp1[k] ++;
			if(!vis[k]) {
				a1.push_back(k);
				vis[k] = true;
			}
		} else {
			int k = std::min(x1, x2);
			mp2[k] ++;
			if(!vis2[k]) {
				a2.push_back(k);
				vis2[k] = true;
			}
		}
	}
	


	std::sort(a1.begin(), a1.end(), [](int a, int b) {
		if(mp1[a] == mp1[b]) {
			return a < b;
		} else {
			return mp1[a] > mp1[b];
		}
	});

	std::sort(a2.begin(), a2.end(), [](int a, int b) {
		if(mp2[a] == mp2[b]) {
			return a < b;
		} else {
			return mp2[a] > mp2[b];
		}
	});

	std::sort(a1.begin(), a1.begin() + l);

	std::sort(a2.begin(), a2.begin() + k);


	for(int i = 0; i < k; i ++) {
		std::cout << a2[i] << " \n"[i == k - 1];
	}

	for(int i = 0; i < l; i ++) {
		std::cout << a1[i] << " \n"[i == l - 1];
	}
}