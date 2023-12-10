#include <iostream>
#include <cstdio>

using i64 = long long;

int main() {
	double a;
	int b;
	char c;

	scanf("%lf,%d,%c", &a, &b, &c);

	printf("%lf,8\n", a);
	printf("%d,4\n", b);
	printf("%c,1", c);
}