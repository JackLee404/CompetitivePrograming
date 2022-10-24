#include <iostream>
#include <map>
#include <cstring>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

int a[N];

int main() {
	int n;

	while (cin >> n) {

		memset(a, 0, sizeof a);
		LL res = 0;

		rep(i, 1, n) {
			int t;
			cin >> t;
			a[t] ++;
		}

		if (a[0]) {
			for (int i = 1; i <= 500; i ++)
				if (a[i] >= 2) {
					res += a[0] * (a[i] * (a[i] - 1)) / 2;
				}
		}

		if (a[0] >= 3) {
			res += ((LL)a[0] * (a[0] - 1) * (a[0] - 2)) / 6;
		}

		for (int i = 1; i <= 500; i ++)
			for (int j = i + 1; j <= 500; j ++)
				for (int k = j + 1; k <= 500; k ++)
					if ((i^j^k) == 0) {
						res += a[i] * a[j] * a[k];
					}

		cout << res << endl;
	}
}
