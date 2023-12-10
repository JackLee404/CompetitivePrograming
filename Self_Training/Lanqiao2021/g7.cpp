#include <iostream>

using i64 = long long;

const int N = 1e7;

int f[2][N];

int main() {
    int n, cnt = 1;

    std::cin >> n;

    if(n == 1) {
        std::cout << 1;
    	return 0;
    }

    f[1 & 1][1] = 1;

    for(int i = 2; i <= n + 1; i ++) {
        for(int j = 1; j <= i; j ++) {
            f[i & 1][j] = f[(i - 1) & 1][j - 1] + f[(i - 1) & 1][j];
            cnt ++;

            // std::cout << j;
            // std::cout << f[i & 1][j] << "\n";
            if(f[i & 1][j] == n) {
                std::cout << cnt;
        		return 0;
            }
        }        
    }
}