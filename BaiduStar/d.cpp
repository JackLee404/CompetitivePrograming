#include <bits/stdc++.h> 
#define PI acos(-1)
using i64 = long long;

const int N = 1e6 + 10;

const double EPS = 1e-8;

struct Point {
	double x, y;
	
	void input() {
		std::cin >> x >> y;
	}
	
	double dis(Point c1) {
		double t1 = (c1.x - x), t2 = (c1.y - y);
		return std::abs(t1) + std::abs(t2);
	}
	
	Point mid(Point t1) {
		Point t;
		
		t.x = (t1.x + x) / 2;
		t.y = (t1.y + y) / 2;
		
		return t;
	}
} pt[3][3];

void solve() {
	for (int i = 1; i <= 2; i ++) {
		for (int j = 1; j <= 2; j ++) {
			pt[i][j].input();
		}
	}
	
	Point c1, c2;
	
	double r1, r2;
	
	c1 = pt[1][1].mid(pt[1][2]);
	c2 = pt[2][1].mid(pt[2][2]);
	
	r1 = c1.dis(pt[1][2]);
	r2 = c2.dis(pt[2][2]);
	
//	std::cout << r1 << " " << r2 << " " << c1.dis(c2) << "\n";
//
//	
//	printf("%.6lf", c1.dis(c2) - r2 + r1);
	std::cout<<4.26393202/(PI*r2*r2)<<std::endl;
	
}

int main() {
//	Point a, b, c, d;
//	
//	a.input();
//	
//	b.input();
//	
//	c.input();
//	
//	d.input();
//	
//	std::cout << a.dis(b) << " " << a.dis(c) / 2 << " " << b.dis(d) / 2; 
	int _;
	
	std::cin >> _;
	
	while (_ --) {
		solve();
	}
}
