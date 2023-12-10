#include <bits/stdc++.h>
#define siz(x) (int) x.size()

using i64 = long long;

std::stack<std::string> s1;
std::unordered_map<std::string, int> mp, ef;

std::string flag;

int state, neg, pos, ans, now;

int checkO(std::string t) {
	if(t[2] != 'n') return -1;
	else return atoi(t.substr(4, siz(t) - 4).c_str());
}

void input(std::string &op, std::string &v, std::string &st, std::string &ed) {
	std::cin >> op;
	if(op == "E") {
		if(s1.size()) {
			if(flag == s1.top()) flag = "-1";
			if(ef[s1.top()]) now --;
			ef[s1.top()] = mp[s1.top()] = 0;

			s1.pop();
		} else state = -1;
	} else {
		std::cin >> v >> st >> ed;


		if(mp[v]) state = -1;
		else mp[v] = 1;

		if(st == "n" && ed == "n") {
			s1.push(v);
		} else if(ed == "n") {
			if(flag == "-1") {
				now ++;
				ans = std::max(now, ans);
				ef[v] = true;
			}
			s1.push(v);
		} else if(st == "n") {
			if(flag == "-1") flag = v;
			s1.push(v);
		} else {
			int k1 = atoi(st.c_str()), k2 = atoi(ed.c_str());	 
			if(k1 > k2) {
				if(flag == "-1") flag = v;
			}
			if(k2 - k1 >= 1000 && flag == "-1") {
				now ++;
				ef[v] = true;
				ans = std::max(ans, now);
			}
			s1.push(v);
		}
	}
}

void solve() {
	int n;
	std::string o;

	mp.clear(), state = ans = now = 0;

	flag = "-1";

	while(s1.size()) s1.pop();

	std::cin >> n >> o;

	int ck = checkO(o);	

	for(int i = 1; i <= n; i ++) {
		std::string v, op, st, ed;
		// if(state == -1) std::cout << i << "\n";
		input(v, op, st, ed);
	}

	// std::cout << ans << "\n";

	if(s1.size()) state = -1;

	if(state == -1) {
		puts("ERR");
	} else if(!ans && ck == -1) {
		puts("Yes");
	} else if(ans == ck) {
		puts("Yes");
	} else {
		puts("No");
	}
}

int main() {
	int _;
	std::cin >> _;

	while(_ --) {
		solve();
	}
}