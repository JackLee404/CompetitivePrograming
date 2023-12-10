#include <iostream>
#include <vector>
using namespace std;

vector<int> g[5010];
 
int main() {
	int n, ans = 0;
	string t;
	cin >> n >> t;
	t = ' ' + t;
	for(int i = 1; i <= n; i ++) {
		g[t[i] - 'a'].push_back(i);
	}
	for(int i = 1; i < n; i ++) {
		bool ok = true;
		int ans = 0;
		for(int l = 1; l + i <= n; l ++) {
			if(t[l] != t[l + i]) ans = l;
			else break;
		}
		cout << ans << "\n";
	}
}