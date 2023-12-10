#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

/*
	dp[i][j] 表示 a串长度为i b串长度为j的最长公共子序列
	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1);
	aabcc 
	abcc
*/
char a[110], b[110];
int dp[110][110], n, m;
set<string> s1;

void go_back(int i, int j, string str) {
	while(i >= 1 && j >= 1) {	
		if(a[i] == b[j]) {
			str = a[i] + str;
			i --, j --;
		} else {
			if(dp[i - 1][j] > dp[i][j - 1]) {
				i --;
			} else if(dp[i - 1][j] < dp[i][j - 1]) {	
				j --;
			} else{
				go_back(i - 1, j, str);
				go_back(i, j - 1, str);
				return;
			}
		}
	}
	if(str.length()) s1.insert(str);
}

int main() {	
	cin >> (a+1) >> (b+1);
	n = strlen(a+1), m = strlen(b+1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(a[i]==b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cout << dp[i][j] << " \n"[j == m];
		}
	}

	go_back(n, m, "");
	for (auto &x: s1) {
		cout << x << "\n";
	}
}