#include <bits/stdc++.h>
#include <numeric>
using namespace std;

const int N = 1e4 + 10;

vector<int> a;

void out(int p1, int p2, int p3) {
	cout << "Outgoing #: " << p1 << "\n";
	cout << "Introverted #: " << p2 << "\n";
	cout << "Diff = " << p3 << "\n";
}
// 1 2 3  3/2 =  1
int main() {
	int n;
	cin >> n;
	a.resize(n);
	for (auto &x: a) cin >> x;
	sort(a.begin(), a.end());
	if(n % 2 == 0) {
		int p1, p2, p3;
		p2 = accumulate(a.begin(), a.begin() + n / 2, 0);
		p1 = accumulate(a.begin() + n / 2, a.end(), 0);
		out(n/2, n/2, abs(p1 - p2));
	}else {
		int p1, p2, p3;
		int k = a[n/2];
		p2 = accumulate(a.begin(), a.begin() + n / 2, 0);
		p1 = accumulate(a.begin() + n / 2, a.end(), 0);
		// cout << p2 << " " << p1 << endl;
		out(n / 2 + 1, n / 2, abs(p1 - p2));
		// if(p1 > p2) p1 += k, out(n / 2 + 1, n / 2, abs(p1 - p2));
		// else p2 += k, out(n / 2, n / 2 + 1, abs(p1 - p2));
	}
}
