#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

string a;
bool check[N];

bool isbol(char a) {
	return a == '!' || a == ',' || a == '?' || a == '\'';
}

string trim(string a) {
	int l;
	for (l = 0; l < a.size(); l ++) {
		if (a[l] != ' ') break;
	}
	int r;
	for (r = (int) a.size() - 1; r >= 0; r --) {
		if (a[r] != ' ') break;
	}
	string n1;
	char last;
	// cout << l << " " << r << endl;
	for (int i = l; i <= r; i ++) {
		if (i < r) {
			if (a[i] == ' ' && (isbol(a[i + 1]) || a[i + 1] == ' ')) {
				continue;
			}
		}
		last = a[i];
		if (a[i] >= 'A' && a[i] <= 'Z') n1.push_back(a[i] + 32);
		else if (a[i] == '?') n1.push_back('!');
		else n1.push_back(a[i]);
	}
	return n1;
}

// string solve(string &a) {
// 	string last, now, ans;
// 	for (int i = 0; i < a.size(); i ++) {
// 		int tj;
// 		for (tj = i; tj < a.size(); tj ++) {
// 			if (a[tj] >= 'a' && a[tj] >= 'z') now.push_back(a[tj]);
// 			else break;
// 		}
// 		if (last.size() && (last == "can" && now == "you")) {
			
// 		}
// 	}
// }

// void solve2(string a) {
// 	for (int )
// }

int main() {
	int n; cin >> n; getchar();
	while (n --) {
		getline(cin, a);
		cout << a << "\n";
		string b = trim(a);
		cout << "AI: ";
		cout << b << endl;
		// cout << solve(b) << endl;
	}
}

/*
	1. 无论说啥先输出
	2. 相邻单词一个空格，首位空格去掉（trim), 标点符号前的空格去掉
	3. 大小字母变小写字母
	4. can you, could you --> I can, I could;
	5. ？->!
	6. 输出
*/