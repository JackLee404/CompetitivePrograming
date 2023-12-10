#include <iostream>
#include <vector>
#include <queue>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> PII;

const int N = 1e3;

int n, q;
long long ans;

int main() {
	cin >> n >> q;
	priority_queue<PII, vector<PII>, greater<PII>> heap[N];
	for (int i = 1; i <= n; i ++) ans += i * i, heap[i].push({0, i});
	while(q--) {
		string op; int a, b, c; cin >> op >> a >> b >> c;
		if (op == "+") {
            cout << a << endl;
			PII lst = heap[a].top();
			heap[a].push({c, b});
			if(c > lst.ff) {
				ans += (lst.ss - b) * a;
                cout << ans << "\n";
			}
		} else if (op == "-") {
			
		}
	}
}