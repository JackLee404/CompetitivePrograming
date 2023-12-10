#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int ty = y;
	y = x - a / b * y, x = ty;
	return d;
}

int main() {
	
}