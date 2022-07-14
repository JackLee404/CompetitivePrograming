#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 1000;

int main(){
	int n, ans = 0, res[maxn];
	memset(res, 0, sizeof(res));
	scanf ("%d", &n);
	for (int i = 1; i <= 100000; i ++){
		int x = i, tot = 0;
		while (x != 0){
			tot += x % 10;
			x /= 10;
		}
		if (!res[tot + i] || res[tot + i] > i) res[tot + i] = i;
	}
	printf("%d", res[n]);
}
