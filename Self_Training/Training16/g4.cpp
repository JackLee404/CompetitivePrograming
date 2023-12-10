#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 10;

int a[N], b[N];
int ma, mb, n;

signed main()
{
	cin >> n;
	cin >> ma;
	for(int i = 1; i <= ma; i ++ ) cin >> a[i];
	for(int i = 1; i <= ma / 2; i ++ ) swap(a[i], a[ma - i + 1]);
	
	cin >> mb;
	for(int i = 1; i <= mb; i ++ ) cin >> b[i];
	for(int i = 1; i <= mb / 2; i ++ ) swap(b[i], b[mb - i + 1]); 
	
	int t = 1, ans = 0;

	long long A = 0, B= 0 ;

	//枚举每个数位
	for(int i = 1; i <= ma; i ++ ) {
		//当前数位贪心最优的进制 
		int z = max(a[i], b[i]) + 1;
		if(z < 2) z = 2; 
		A += a[i] * t;
		A %= mod;
		t = t * z % mod;
	}

		//枚举每个数位
	for(int i = 1; i <= ma; i ++ ) {
		//当前数位贪心最优的进制 
		int z = max(a[i], b[i]) + 1;
		if(z < 2) z = 2; 
		B += b[i] * t;
		B %= mod;
		t = t * z % mod;
	}
	
	
	std::cout << A - B;
	
	return 0;
}