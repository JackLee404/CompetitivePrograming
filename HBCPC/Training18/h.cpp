#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
#define per(i, j, k) for (int i = j; i >= k; i --)
using namespace std;

const int N = 1e5 + 10;

int a[300];

int main() {
	int n, k, s, cnt = 0;
	cin >> n >> k >> s;
	rep (i, 1, n) {
		int c, d;
		cin >> c >> d;
        if (c >= 175 && d >= s) {
            cnt ++;
        } else {
            a[c] ++;
        }
    }
    per (i, 290, 175) {
        if (a[i] < k) cnt += a[i];
        else cnt += k;
    }
    cout << cnt;
}