#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int idx;
char b[N];
int a[256];

vector<int> step;

string c, unit;

int st[N];


struct node {
	vector<int> a;
	int flag, id;	
};


bool cmp(node a, node c) {
	int len = min(a.a.size(), c.a.size());
	if (a.flag == c.flag && a.a.size() == c.a.size()) {
		bool flag1 = true;
		for (int i = 0; i < a.a.size(); i ++) {
			if (b[a.a[i]] != b[c.a[i]]) {
				flag1 = false;	
				break;
			}	
		}
		if (flag1) return false;
	}
	for (int i = 0, j = 0; i < len; i ++, j ++) {
		if (i >= a.a.size()) i = a.flag;
		else if (j >= c.a.size()) j = c.flag;
		if (b[a.a[i]] != b[c.a[j]]) {
			if (b[a.a[i]] < b[c.a[j]])
				return true;
			else
				return false;
		}	
	}
	return false;
}




int main() {
	a['A'] = 1, a['B'] = 2, a['C'] = 3, a['D'] = 4, a['E'] = 5, a['F'] = 6;
	cin >> b;
	int len = (int) strlen(b);

	int lflag = 0;
	string last;

	node mx1;
	for (int i = 0; i < len; i ++) {
		c.clear();
		memset(st, -1, sizeof st);
		int idx = i;
		node now;
		now.id = i;

		while (true) {
			now.a.push_back(idx);
			if (st[idx] != -1) {
				now.flag = st[idx];	
				// for (int i = 0; i < now.a.size(); i ++) {
				// 	cout << b[now.a[i]];
				// }
				// cout << "\n" << now.flag << endl;
				break;
			}
			st[idx] = true;
			c.push_back(b[idx]);
			idx += a[b[idx]];
			if (idx >= len) {
				idx %= len;
			}
	    }
	    if (i == 0) {
	    	mx1 = now;
	    } else {
	    	if (cmp(now, mx1) == true) {
	    		mx1 = now;
	    	}
	    }
	}
	cout << mx1.id;
}