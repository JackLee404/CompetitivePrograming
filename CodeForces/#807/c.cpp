#include <bits/stdc++.h>
#include <cstring>
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
#define f first
#define s second
using namespace std;
const int N = 2 * 1e5 + 10;
char s[N];
struct node{long long l, r, tl, tr;}a[100];
void solve(){
	int cnt = 0;
	int n, c, q;
	cin >> n >> c >> q;
	cin >> s;
	long long len = strlen(s);
	rep (i, 1, c){
		long long l, r;
		cin >> l >> r;
		a[cnt++] = {len + 1, len + r - l + 1, l, r};
		len += r - l + 1;
	}
	int size1 = strlen(s);
	rep (i, 1, q){
		long long t;
		cin >> t;
		while (t > size1){
			rep (i, 0, cnt - 1){
				if (t >= a[i].l && t <= a[i].r){
					t = t - a[i].l + a[i].tl;
					break;
				}
			}
		}
		cout << s[t - 1] << endl;
	}
}

int main(){
	int _;
	cin >> _;
	while (_--){
		solve();
	}
}
