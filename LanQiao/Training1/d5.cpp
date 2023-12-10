#include <iostream>
#include <utility>
#include <map>
#define mk std::make_pair
#define ff first
#define ss second
typedef long long i64;
typedef std::pair<i64, i64> pii;

// dp字典存储 <最大能减的数，当前数> -> <最小操作数, 余数>
std::map<pii, pii> dp;

// i64 ans2;

pii dfs(pii a) {
	// ans2 ++;
	// 如果当前数据<10, 直接返回答案， 注意到(0, 0) 的最小操作数还是0
	if(a.ss < 10)
		return mk(a.ss || a.ff, a.ss - std::max(a.ss, a.ff));

	// 找到数据直接返回<最小操作数, 余数>
	if(dp.find(a) != dp.end())
		return dp[a];

	// 截断最高位数字
	i64 p = 1;

	while(p <= a.ss / 10)
		p *= 10;

	// 低位运算
	pii b1 = dfs(mk(std::max(a.ff, a.ss / p), a.ss % p));

	// 高位运算
	pii b2 = dfs(mk(a.ff, a.ss / p * p + b1.ss));

	return dp[a] = mk(b1.ff + b2.ff, b2.ss);
}

int main() {
	i64 n;

	std::cin >> n;

	std::cout << dfs(mk(0, n)).ff;

	// std::cout << "\n" << ans2 << "\n";
}