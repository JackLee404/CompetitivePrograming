#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

void out(std::vector<int> &a) {
	for (auto x: a) {
		std::cout << x;
	}
	return (void) puts("");
}

std::vector<int> add(std::vector<int> &a, std::vector<int> &b) {
	if (a.size() < b.size()) return add(b, a);

	int last = 0;

	std::vector<int> res;

	for (int i = 0; i < (int) a.size(); i ++) {
		int t = a[i];
		
		if (i < b.size()) t += b[i];	

		t += last;

		last = t / 10;

		t %= 10;

		res.push_back(t);
	}

	if (last) res.push_back(last);

	return res;
}

std::vector<int> mul(std::vector<int> &a, std::vector<int> &b) {
	if (a.size() < b.size()) return mul(b, a);

	std::vector<int> res;

	res.push_back(0);

 	for (int i = 0; i < (int) b.size(); i ++) {
 		int last = 0;
 		std::vector<int> v1(i, 0);
 		
		for (int j = 0; j < (int) a.size(); j ++) {
			int t = b[i] * a[j];

			t += last;

			last = t / 10;

			v1.push_back(t % 10);
		}

		if (last) v1.push_back(last);
		
		res = add(res, v1);
	}

	// out(res);

	return res;
}

std::vector<int> quick_pow(std::vector<int> a, int b) {
	std::vector<int> res;

	res.push_back(1);

	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}

	return res;
}

std::vector<int> to_vec(int x) {
	std::vector<int> v1;

	if (!x) return v1.push_back(0), v1;

	while (x) v1.push_back(x % 10), x /= 10;

	return v1;
}

bool check(std::vector<int> &a, std::vector<int> &b) {
	if (a.size() != b.size()) return false;

	for (int i = 0; i < a.size(); i ++) {
		if (a[i] != b[i]) return false;
	}

	return true;
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		std::vector<int> r1 = quick_pow(to_vec(a), b);

		std::vector<int> r2 = quick_pow(to_vec(c), d);

		puts(check(r1, r2)?"YES":"NO");
	}

}