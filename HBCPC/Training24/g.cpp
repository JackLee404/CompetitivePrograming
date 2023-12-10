#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, ans;
	getline(cin, a);
	for (int i = 0; i < a.size(); i ++) {
		int ti, cnt = 0, ck = 1;
		for (ti = i; ti < a.size(); ti ++) {
			if (a[ti] == '6') cnt ++;
			else if (a[ti] != ' '){
				ck = 0;
				break;
			} else {
				break;
			}
		}
		if (ck) {
			if (cnt > 9)
				ans += "27";
			else if (cnt > 3)
				ans += "9";
			else
				ans.push_back(a[i]);
			i = ti;
		} else {
			ans.push_back(a[i]);
		}
	}
}