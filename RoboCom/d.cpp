#include <bits/stdc++.h>
#define psi std::pair<std::string, int>
#define ff first
#define ss second

using i64 = long long;

int n, m;

std::map<psi, std::vector<psi>> mp;

//std::map<std::pair<psi, psi>, bool> est;

std::map<psi, bool> st;

std::set<psi> s1;

std::vector<psi> v1, v2;

psi start;

void dfs(psi u) {
	st[u] = true;
	
	
	if (st[{u.ff, !u.ss}]) {
		if (!v2.size() || v1.size() < v2.size()) v2 = v1;
		return;
	}
	
		
	for (auto x: mp[u]) {
		if (st[x]) continue;
		
		st[x] = true;
		
		v1.push_back(x);
		 
		dfs(x);
		
		st[x] = false;
		
		v1.pop_back();
	}
}

int main() {
	std::cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		psi a, b;
		
		std::cin >> a.ff >> a.ss >> b.ff >> b.ss;
		
		mp[a].push_back(b);
		
		s1.insert(a), s1.insert(b);
	}
	
	for (auto x: s1) {
		start = x;
		
		v1.clear();
		
		v1.push_back(x);
		
		st.clear();
		
		dfs(x);
		
		v1.pop_back();
	}
	
	for (int i = 0; i < (int) v2.size(); i ++) {
		std::cout << v2[i].ff << " " << v2[i].ss << " ";
	}
	
	std::cout << "= ";
	
	std::cout << v2[0].ff << " " << v2[0].ss << " " << v2[(int) v2.size() - 1].ff << " " << v2[(int) v2.size() - 1].ss;
}
