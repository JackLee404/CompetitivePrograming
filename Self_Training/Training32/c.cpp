#include<iostream>
using namespace std;

long long int f[2023][11][2023];  //表示前2022个物品选择10个物品，体积总和为2022的方案个数  ,,数组下标为1开始，所以使2023，11，2023

int i, j, k;
int main()
{
    for (i = 0; i <= 2022; i++)  //因为体积为0，物品为0的所有情况都只有一种选择，即什么都不选
        f[i][0][0] = 1;
    for (i= 1; i <= 2022; i++)  //枚举所有物品
    {
        for (j = 1; j <= 10; j++)   //选了几个物品
        {
            for (k = 1; k <= 2022; k++)  //枚举体积
            {
                f[i][j][k] = f[i-1][j][k];  //不选第i个物品
                if (k >= i)  //选第i个物品
                    f[i][j][k] += f[i-1][j - 1][k - i];
            }
        }
    }
    cout << f[2022][10][2022] << " " << f[2013][10][2022];
    return 0;
}