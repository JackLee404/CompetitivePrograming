#include <bits/stdc++.h>
#include <cstdio>
#define LOCAL
const int MOD = 1e5;
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << a / b;
	int k = a % b;
	if (!c) return 0;
	cout << ".";
	for (int i = 1; i <= c; i ++){
		cout << k * 10 / b;
		k = (k * 10) % b;
	}
}
