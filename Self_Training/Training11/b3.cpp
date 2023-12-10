#include <iostream>

using i64 = long long;

const int N = 1e5 + 10;

int p[N];

int find(int x) {
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void add(int a, int b) {
	p[find(a)] = find(b);
}

int main() {
	int n, m;

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) p[i] = i;

	while(m --) {
		std::string act;

		int a, b;

		// scanf("%s%d%d", act, a, b);
 
		std::cin >> act >> a >> b;

		if(act == "M") {
			add(a, b);
		} else {
			std::cout << (find(a) == find(b)?"Yes":"No") << "\n";
		}
	}
}