#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define PII pair<int, int>
using namespace std;
string a[10];
bool st[100], st2[100];
bool st3[100][100];
int n, k, cnt, cnt2;

bool check(int i, int j) {
	return a[i][j] == '#' && !st[i] && !st2[j];
}

void dfs(int i) {
	if (cnt == k) {
		cnt2 ++;
		return;
	}
	else if (i > n && cnt < k) {
		return;
	}

	rep (j, 1, n) {
		if (check(i, j)) {
			st[i] = true;
			st2[j] = true;
			cnt ++;
			dfs(i + 1);
			st[i] = false;
			st2[j] = false;
			cnt --;
		}
	}
	dfs(i + 1); // 什么都不选的情况
}

int main() {
	while (cin >> n >> k && n != -1 && k != -1) {
		memset(st, 0, sizeof st);
		memset(st2, 0, sizeof st2);
		cnt = 0, cnt2 = 0;
		rep (i, 1, n) {
			rep (j, 1, n) {
				cin >> a[i][j];
			}
		}
		dfs(1);
		cout << cnt2 << endl;
	}
}