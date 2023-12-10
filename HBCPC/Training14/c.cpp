#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <algorithm>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define siz(v) ((int) v.size())
#define judge(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define mahaton(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))
using namespace std;

typedef pair<int, int> PII;


const int N = 1e5 + 10;


/* 
	假设对于 s1来说s4是他的右小于数边界
	s1 s2 s3 s4 s5

	那么有
	且s4 < s1
	V 表示s4后边的数的集合
	那么 对于任意x属于V, 都有x > s1;
	那么对于s2来说 s4也是他的答案

*/
int a[N], f[N], b[N];

vector<int> v1;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];

	for (int i = n - 1; i >= 0; i --) {
		
	}


	for (int i = 0; i < n; i ++) {
		cout << b[i] << " ";
	}
}