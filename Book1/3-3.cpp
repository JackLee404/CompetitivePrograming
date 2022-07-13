#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#define LOCAL
using namespace std;

int main(){
	int n, a[500][500];
	memset(a, 0, sizeof(a));
	cin >> n;
	int x = 0, y = n, tot = 1;
	while (tot < n * n + 1){
		while (x < n && !a[x + 1][y]) a[++ x][y] = tot ++;
		while (y > 1 && !a[x][y - 1]) a[x][-- y] = tot ++;
		while (x > 1 && !a[x - 1][y]) a[-- x][y] = tot ++; 
		while (y < n - 1 && !a[x][y + 1]) a[x][++ y] = tot ++;
	} 
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++)
			printf("%3d", a[i][j]);
		cout << "\n";
	}
	
}

/*
	arry which is shape of python
	 10 11 12  1
	  9 16 13  2
	  8 15 14  3
	  7  6  5  4
*/
