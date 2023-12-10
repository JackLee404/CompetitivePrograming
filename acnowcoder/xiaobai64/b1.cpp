#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair<int,int> PII;

const int N = 1e3 + 10;

int n, m, ans;

char a[N][N];

vector<int> v1;

int main() {
	bool ck = false;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= m; j ++) {
    		if (a[i][j] == '#') {
    			int x0, y0;
    			if (i > n / 2) {
    				x0 = n;
    			} else x0 = 1;
    			if (j > m / 2) {
    				y0 = m;
    			} else y0 = 1;
    			ans = max(ans, abs(x0 - i) + abs(y0 - j));
    		}
    	}
    }
}