#include <iostream>

using namespace std;

int main() {
	double a, b, t;
	cin >> a >> b;
	printf("%.1lf\n", (t = a/b * (a /b)));
	if (t > 25) puts("PANG");
	else put("Hai Xing");
}