#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i --)
using namespace std;

const int N = 10000;

int primes[N], d[N], ed, st;
string ended, start;

inline bool prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i ++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

void bfs(string start) {
	queue<string> q1;
	q1.push(start);
	d[st] = 0;
	memset(d, -1, sizeof d);
	while (q1.size()) {
		string t = q1.front(); q1.pop();
		int nt = atoi(t.c_str());
		if (nt == ed) {
			return;
		}
		rep (i, 0, (int) t.size() - 1) {
			rep (j, '0', '9') {
				if (j == t[i]) continue;
				string b = t; b[i] = j;
				int k = atoi(b.c_str());
				if (d[k] == -1 && primes[k]) {
					q1.push(b);
					d[k] = d[nt] + 1;
				}
			}
		}
	}
}

int main() { 
	for (int i = 1000; i <= 9999; i ++) {
		primes[i] = (int) prime(i);
	}
	int _;
	cin >> _;
	while (_ --) {
		cin >> start >> ended;
		ed = atoi(ended.c_str()), st = atoi(start.c_str());
		bfs(start);
		if (ed == st) {
			cout << 0 << endl;
		} else {
			if (d[ed] == -1)
				puts("Impossible");
			else
				cout << d[ed] + 1 << endl;
		}
	}
}