#include <stdio.h>
#include <iostream>
#include <algorithm>

const int N = 1000;

using namespace std;

int a[N];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n, cmp);

	for(int i = 1; i <= n; i ++) {
		cout << a[i] << " \n"[i == n];
	}
}	
