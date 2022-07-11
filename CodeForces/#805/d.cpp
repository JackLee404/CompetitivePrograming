#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 10;
int main(){
	int t, f[26];
	for (int i = 0; i <= 25; i ++) f[i] = i + 1;
	cin >> t;
	while ( t --){
		string w;
		int p, cnt = 0;
		vector<pair<char, int>> w2;
		vector<bool> st(N, false);
		cin >> w >> p;
		for (int i = 0; i < w.size(); ++ i){
			cnt += f[w[i] - 'a'];
			w2.push_back({w[i], i});
		}
		if (cnt <= p){
			cout << w << endl;
			continue;
		}
		sort(w2.begin(), w2.end());
		for (int i = w2.size() - 1; i >= 0; -- i){
			if (cnt > p){
				cnt -= f[w2[i].first - 'a'];
				st[w2[i].second] = 1;
			}else break;
		}
		for (int i = 0; i < w.size(); ++ i) if (!st[i])cout << w[i];
		cout << "\n";
	}
}

/*
  https://codeforces.com/contest/1702/problem/D
*/
