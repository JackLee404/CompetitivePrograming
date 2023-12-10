#include <iostream>
#include <cstring>

using i64 = long long;

int vis[10000];

bool check(int x, int y, int z) {
	memset(vis, 0, sizeof vis);

	vis[x] = vis[y] = vis[z] = 1;

	return (vis[3] && vis[6] && vis[9]);
}


int main() {
	int x, y, z;

	std::cin >> x >> y >> z;
    
    int ans = -1;

// 	for(int i = 1; i <= 100; i ++) {
		
		
// 		int k1 = x % 10, k2 = y % 10, k3 = z % 10;
        

// 		if(check(k1, k2, k3)) {
// 			ans = i;
// //             ok = true;
//             break;
// 		}
// 	}

	int cnt = 0;

	while(cnt < 100) {
		x ++, y ++, z ++, cnt ++;

		int k1 = x % 10, k2 = y % 10, k3 = z % 10;

		if(check(k1, k2, k3)) {
			ans = cnt;
            break;
		}
	}
    
    if(ans == -1)
	    std::cout << ":so sad!";
    else
        std::cout << ans;
}