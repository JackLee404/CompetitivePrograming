#include <iostream>
#include <vector>

using i64 = long long;

const int N = 200;

int arr[] = {0, 99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77};

bool vis[N][N];

int main() {
	int cnt = 0;
 
	for(int i = 1; i <= 30; i ++) {
		for(int j = 1; j <= 30; j ++) {
			if(i == j) continue;
			if(arr[i] * arr[j] >= 2022 && !vis[i][j]) {
				// std::cout << arr[i] << " " << arr[j] << "\n";
				vis[i][j] = vis[j][i] = true;
				cnt ++;
			}
		}
	}

	std::cout << cnt;
}