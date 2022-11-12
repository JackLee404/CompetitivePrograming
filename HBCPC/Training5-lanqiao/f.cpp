#include <iostream>
#include <cctype>

using namespace std;

typedef long long LL;

int n;

struct date {
	int h, m, s, u, i;
} a[200];

LL ans;


int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		scanf("%d:%d:%d %d %d", &a[i].h, &a[i].m, &a[i].s, &a[i].u, &a[i].i);
		if (i > 1) {
			LL time1 = a[i].h * 60 * 60 + a[i].m * 60 + a[i].s;
			LL time2 = a[i - 1].h * 60 * 60 + a[i - 1].m * 60 + a[i - 1].s;
			ans += (time1 - time2) * (a[i - 1].u * a[i - 1].i);
		}
	}
	cout << ans;
}