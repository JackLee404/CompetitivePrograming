#include <iostream>
#include <cstring>
#define F(i, j, k) for (int i = j; i <= k; ++ i)
using namespace std;
int n, m, k;

void solve(){
	bool vis[30];
	memset(vis, 0, sizeof(vis));
	int tot = 0, foot1 = 1, foot2 = n;;
	while (tot < n){
		F(i, 1, k){
			if (vis[foot1]) i --;
			if (i != k){
				foot1 ++;
				if (foot1 == n + 1) foot1 = 1; 
			}
		}
		F(i, 1, m){
			if (vis[foot2]) i --;
			if (i != m){
				foot2 --;
				if (!foot2) foot2 = n;
			}
		}
		vis[foot1] = vis[foot2] = 1;
		if (foot1 == foot2)printf("%3d", foot2), tot += 1;
		else printf("%3d%3d", foot1, foot2), tot += 2;
		if (tot != n) cout << ",";
	}
}


int main(){
	while (cin >> n >> k >> m && (n || k || m)){
		solve();
		cout << "\n";
	}
}
