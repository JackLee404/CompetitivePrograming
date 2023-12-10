#include <bits/stdc++.h>
#include <cctype>

using i64 = long long;

std::string t, ans;

int check(int x) {
	if(t[x] <= 'Z' && t[x] >= 'A')
		return 1;
	if(t[x] <= 'z' && t[x] >= 'a')
		return 2;
	if(t[x] <= '9' && t[x] >= '1')
		return 3;
	return -1;
}

int main() {
	int p1, p2, p3;

	std::cin >> p1 >> p2 >> p3;

	std::cin >> t;

	for(int i = 0; i < t.size(); i ++) {
		if(t[i] == '-' && t[i - 1] + 1 == t[i + 1]) continue;
		int ck = check(i - 1);
		if(t[i] == '-' && i < (int)t.size() - 1 && check(i - 1) == check(i + 1) && t[i - 1] < t[i + 1] && ck != 1) {
			std::string t2;
			char l = t[i - 1], r = t[i + 1];
			for(char w = l + 1; w < r; w ++) {
				for(int j = 1; j <= p2; j ++) {
					if(p1 == 3)
						t2.push_back('*');
					else if(ck != 3)
						t2.push_back(p1 == 2?toupper(w):tolower(w));
					else
						t2.push_back(w);
				}
			}
			if(p3 == 2) std::reverse(t2.begin(), t2.end());
			ans = ans + t2;
		} else ans.push_back(t[i]);
	}

	std::cout << ans;
}