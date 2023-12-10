#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define siz(v) ((int) v.size())
#define judge(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define mahaton(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))
using namespace std;

typedef pair<int, int> PII;


set<pair<string, string>> st;

int main() {
	int n;
	cin >> n;
	while (n --) {
		string a, b;
		cin >> a >> b;
		st.insert({a, b});
	}
	cout << st.size();
}