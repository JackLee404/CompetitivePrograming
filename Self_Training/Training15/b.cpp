#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

int a[N];

int main() {
	double a;

	std::cin >> a;

	if(a<0) a *= -1;

	printf("%.2lf", a);
}