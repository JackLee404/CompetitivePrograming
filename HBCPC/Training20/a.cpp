#include <bits/stdc++.h>

using namespace std;

int a[300], cnt;
string t;

void out(char x) {
	cout << x << " \0"[++cnt == t.size()];
}

bool check(int i) {
    if (t[i] != '+' && t[i] != '-') return false;
	if (isdigit(t[i - 1]) || t[i - 1] == ')' || t[i - 1] == '.') return false;
	return true;
}

int main() {
	stack<char> s1;
	a['/'] = 1, a['*'] = 1, a['+'] = 0, a['-'] = 0;
	cin >> t;

	for (auto &x: t) {
		if (x == '(' || x == ')') {
			cnt ++;
		}
	}
    
	for (int i = 0; i < t.size(); i ++) {
		char x = t[i];
		if (isdigit(x)||x == '.') {
			int pos = i;
			while (pos < t.size() && isdigit(t[pos]) || t[pos] == '.') {
				cout << t[pos++], cnt ++;
			}
			if (cnt != t.size()) cout << " ";
			i = (pos == i?i:pos-1);
		} else {
			if (check(i)) {
				if (x == '+') {
					cnt ++;
					continue;
				}
				cout << x, cnt ++;
				continue;
			}
			if (x == '(') s1.push(x);
			else if(x == ')') {
				while (s1.size() && s1.top() != '(') {
					out(s1.top()), s1.pop();
				}
				if (s1.size()) s1.pop(); // 防止异常
			}else {
				while (s1.size() && s1.top() != '(' && a[s1.top()] >= a[x]) {
					out(s1.top()), s1.pop();
				}
				s1.push(x);
			}
		}
	}
	while (s1.size()) {
		out(s1.top()), s1.pop();
	}
}