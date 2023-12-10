#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#define f first
#define s second
using namespace std;
typedef pair<int, int> PII;

const int N = 200;

vector<PII> point;
bool ans;
map<pair<int, int>, bool> vis;


int n, d;

bool check1(double x, double y, double x1, double y1) {
	double c = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
	c -= 15;
	return c <= d;
}


bool check2(double x, double y, double x1, double y1) {
	double c = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
	return c <= d;
}

void bfs() {
	queue<PII> q1;
	for (auto &x: point) {
		if (check1(0, 0, x.f, x.s)) {
			vis[{x.f, x.s}] = true;
			q1.push({x.f,x.s});
		}
	}
	while(q1.size()) {
		auto t = q1.front(); q1.pop();
		if ((t.f+d>=50||t.f-d<=-50) || (t.s+d>=50||t.s-d<=-50)) {
			ans = true;
			return;
		}
		for (auto &x: point) {
			if (!vis[{x.f, x.s}] && check2(t.f, t.s, x.f, x.s)) {
				vis[{x.f, x.s}] = true;
				q1.push({x.f, x.s});
			}
		}
	}
}

int main() {
	cin >> n >> d;
	point.resize(n);
	for (auto &x: point) cin >> x.f >> x.s;
	bfs();
	puts(ans?"Yes":"No");
}