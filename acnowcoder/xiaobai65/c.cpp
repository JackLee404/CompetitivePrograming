#include <iostream>
#include <list>
#define ll long long
#define f first
#define s second
#define Inf 0x3f3f3f3f
#define NInf -0x3f3f3f3f
#define pii pair<int, int>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e6 + 10;


int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, k; cin >> n >> k;
	rep(i, 1, n) {
		a[i] = i + 1, b[i] = i - 1;
	}
	rep(i, 1, k) {
		int op, x;
		cin >> op >> x;
		if(op == 1) {
			if(i != n) {
				b[a[i]] = b[i];
				a[b[i]] = a[i];
			}
		} else if(op == 2) {
			cout << a[i] << "\n";
		}
	}
}	