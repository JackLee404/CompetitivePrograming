#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

const int N = 5e5 + 10;

struct node {
	int D[9], x, y;
};

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};


int cantor(struct node p) {
	int sum = 0;
	// fac = 8!
	int fac = 40320;

	for (int i = 0; i < 9; i ++) {
		int cnt = 0;
		for (int j = i + 1; j < 9; j ++) {
			// 计算其右侧比当前数小的数
			if (p.D[j] < p.D[i]) {
				cnt ++;
			}
		}
		sum += fac * cnt;
		if (i == 8)
			return sum;
		// 因为康托展开中的阶乘是递减的, 所以我们通过除来递减
		fac /= 8 - i;
	}
}



void init() {
	struct node p, t;
	for (int i = 0; i < 9; i ++) {
		p.D[i] = i + 1;
	}
	for (int i = 0; i < 9; i ++) {
		t = p;
		t.D[i] = 0;
		t.x = i / 3;
		t.y = i % 3;	
	}
}


int main() {
	int a, b;
	cin >> a >> b;
	cout << a << b;
}