#include <bits/stdc++.h>
#define ff first
#define ss second
typedef std::pair<int, int> PII;
using i64 = long long;

const int N = 2e5 + 10;

std::pair<int, int> a[N];

void solve() {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h1;

	int n;

	std::cin >> n;

	bool ok = false;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i].ss;

		if (a[i].ss != 0) ok = true;

		a[i].ff = 1;

		h1.push(a[i]);
	}

	if (!ok) {
		puts("0");
		return;
	}

	/*
		1 10 100

		(1, 1) (10, 1) (100, 1)

		(9, 2) (90, 2)

		(81, 3)
	*/

	int mx = n - 1, cnt = 0, id = 2;

	while (h1.size() > 1) {
		PII t1 = h1.top(); h1.pop();		

		PII t2 = h1.top();

		t2.ss -= t1.ss;

		// std::cout << t2.ss << "\n";

		t2.ff = id;

		cnt ++;

		if (cnt == mx) {
			h1.pop();
			mx --, cnt = 0, id ++;
		}

		h1.push(t2);

		// std::cout << "size: " << h1.size() << "\n";
	}

	std::cout << h1.top().ss << "\n";
}

int main() {
	int _; std::cin >> _;	

	while (_ --) {solve();}
}