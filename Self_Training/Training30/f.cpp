#include <iostream>
#include <cmath>
#include <algorithm>

using i64 = long long;

const int N = 1e5 + 10;

struct Point{
	double x, y;
	bool operator<(const Point t) const {
		if (x == t.x) return y < t.y;
		return x < t.x;
	}
} p[N], s[N];

int n, tt;

double cross(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dis(Point a, Point b) {
	double t1 = a.x - b.x, t2 = a.y - b.y;
	return sqrt(t1 * t1 + t2 * t2);
}

double Andrew() {
	std::sort(p + 1, p + 1 + n); // 极角排序

	// 下凸包
	for (int i = 1; i <= n; i ++) {
		while (tt > 1 && cross(s[tt - 1], s[tt], p[i]) <= 0) tt --;
		s[++ tt] = p[i];
	}	

	int t = tt;

	// 上凸包
	for (int i = n - 1; i >= 1; i --) {
		while (tt > t && cross(s[tt - 1], s[tt], p[i]) <= 0) tt --;
		s[++ tt] = p[i];
	}

	double res = 0;

	for (int i = 1; i < tt; i ++) res += dis(s[i], s[i + 1]);

	return res;
}

int main() {

}