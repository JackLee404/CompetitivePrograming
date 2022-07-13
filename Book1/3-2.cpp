#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#define LOCAL
const int MOD = 1e5;
using namespace std;

int main(){
	int n, k, a[100010];
	memset(a, 0, sizeof(a));
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= k; i ++){
		for (int j = 1; j <= n; j ++)
			if (j % i == 0) a[i] = !a[i];
	}
	int cnt = 0;
	for (int j = 1; j <= n; j ++)
		if (!a[j]) cout << j << " "; 
}
