#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n + 1), f(n + 1);	
	for (int i = 1; i <= n; i ++) cin >> a[i], f[i] = f[i - 1]^a[i];
	for (int i = 1, j = 1; i <= n; i ++) {
		int now = a[i];
		for (;j <= 1 && (now ^ a[j] > now); j ++) now^=a[j];
	}
}