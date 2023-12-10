#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int siz[3], d[110][110][110];

struct tuples {
	int a[3];
};

int ans;

// push from i to j
tuples push(tuples t, int i, int j) {
	tuples res = t;
	if (t.a[i] > siz[j] - t.a[j]) {
		res.a[i] -= (siz[j] - res.a[j]), res.a[j] = siz[j]; 
	} else {
		res.a[j] += res.a[i], res.a[i] = 0;
	}
	return res;
}

bool full(tuples a, int i) {
	return a.a[i] == siz[i];
}

bool check(tuples a) {
	int cnt = 0;
	for (int i = 0; i <= 2; i ++) {
		if (a.a[i] == siz[0] / 2)
			cnt ++;
	}
	return cnt == 2;
}


bool bfs() {
	queue<tuples> q1;
	tuples start;
	start.a[0] = siz[0], start.a[1] = 0, start.a[2] = 0;
	memset(d, -1, sizeof d);
	d[siz[0]][0][0] = 0;
	q1.push(start);
	while (q1.size()) {
		tuples t = q1.front(); q1.pop();
		if (check(t)) {
			cout << d[t.a[0]][t.a[1]][t.a[2]] << endl;
			return true;
		}
		for (int i = 0; i <= 2; i ++) {
			for (int j = 0; j <= 2; j ++) {
				if (i == j) continue;
				if (t.a[i] && !full(t, j)) {
					tuples res = push(t, i, j);
					if (d[res.a[0]][res.a[1]][res.a[2]] == -1) {
						d[res.a[0]][res.a[1]][res.a[2]] = d[t.a[0]][t.a[1]][t.a[2]] + 1;
						q1.push(res);
					}
				}
			}
		}
	}
	return false;
}

int main() {
	while(cin >> siz[0] >> siz[1] >> siz[2] && siz[0] && siz[1] && siz[2]) {
		if (siz[0] % 2 != 0) {
			cout << "NO" << endl;
		} else {
			bool check = bfs();
			if (!check) cout << "NO" << endl;
		}
	}
}



/*
	7 4 3
	4 1 3
	3
	  1 2
	  1
	三次
*/