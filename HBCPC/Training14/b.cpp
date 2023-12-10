#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#include <stack>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define siz(v) ((int) v.size())
#define judge(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define mahaton(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))
using namespace std;

typedef pair<int, int> PII;

vector<char> v1;

void push1(char a) {
	bool flag = false;
	while (!v1.empty() && v1.back() == a) {
		v1.pop_back();
		flag = true;
	}
	if (!flag) v1.push_back(a);
}

int main() {
	string b;
	cin >> b;

	for (int i = 0; i < siz(b); i ++) {
		// cout << b[i];
		if (!i) v1.push_back(b[i]);
		else push1(b[i]);
	}	

	for (auto& v: v1) {
		cout << v;
	}
}