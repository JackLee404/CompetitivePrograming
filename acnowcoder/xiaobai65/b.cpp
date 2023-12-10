#include <bits/stdc++.h>
#include <cstring>
#include <cmath>
#define ll long long
#define f first
#define s second
#define Inf 0x3f3f3f3f
#define NInf -0x3f3f3f3f
#define pii pair<int, int>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e6 + 10;
int ne[N];

bool ok;

void init_kmp(char p[], int m){
	ne[1] = 0;
	for (int i = 2, j = 0; i <= m; ++ i){
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[j + 1] == p[i]) j ++;
		ne[i] = j;
	}
}
void kmp(char a[], char p[], int n, int m){
	for (int i = 1, j = 0; i <= n; ++ i){
		while (j && p[j + 1] != a[i]) j = ne[j];
		if (a[i] == p[j + 1]) j ++;
		if (j == m) {
			ok = true;
		}
	}
}
int getlen(char a[]){
	int i = 1;
	while (a[i]) i ++;
	return i - 1;
}
int main(){
	char a[N], p[N];
	int n, m, ct1 = 0, ct2 = 0;

	cin >> n >> m;

	rep(i, 1, n) {
		char c; cin >> c;
		if(islower(c)) {
			a[++ct1] = c;
		}
	}
	rep(i, 1, m) {
		char c; cin >> c;
		if(islower(c)) {
			p[++ct2] = c;
		}
	}

	n = ct1, m = ct2;

	init_kmp(p, m);
	kmp(a, p, n, m);
	puts(ok?"YES":"NO");
}