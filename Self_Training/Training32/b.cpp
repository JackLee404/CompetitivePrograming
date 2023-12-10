#include <iostream>
#include <cstring>
#define INF 
using i64 = long long;
const int N = 2030;

int n;

i64 dp[N][N][11];
// dp[i][j][z] 表示考虑前i个物品，当和为j时，物品数为z的方案数
// dp[i][j] = std::max(dp[i - 1][j], )
i64 get(i64 x) {
  if (x == 9187201950435737471) return 0;
  else return x;
}
int main()
{
  memset(dp, 0x7f, sizeof dp);
  std::cin >> n;
  
  dp[0][0][0] = 1;

  // std::cout << (dp[0][0][0]) << "\n";

  for (int i = 1; i <= 2022; i ++) {
    dp[i][0][0] = 1;
    for (int x = 1; x <= 2022; x ++) {
      for (int k = 1; k <= 10; k ++) {
        dp[i][x][k] = get(dp[i - 1][x][k]);
        
        if (x >= i)
          dp[i][x][k] += get(dp[i - 1][x - i][k - 1]);
      }
    }
  }

  // std::cout << dp[2022][9][9] << "\n";

  std::cout << dp[n][2022][10] << "\n";
  return 0;
}