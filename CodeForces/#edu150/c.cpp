#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
inline T nxt() {
	T x;
	std::cin >> x;
	return x;
}

/*
	s < 2e5

	1, 10, 100, 1000, 10000

	如果 100 negtive sum ... other value greater than 100
*/

i64 val[256];

i64 eval(std::string s) {
	std::reverse(s.begin(), s.end());

	i64 ans = 0;
	int mx_id = -1;

	for (auto &x: s) {
		if (mx_id > x) {
			ans -= val[(int) x];
		} else ans += val[(int) x];

		mx_id = std::max(mx_id, (int) x);
	}

	return ans;
}

void solve() {
    std::string t;

    std::cin >> t; 

    std::string b = "ABCDE";

    std::vector<std::string> v1;

    for (int i = 0; i < b.size(); i ++) {
    	for (int j = 0; j < b.size(); j ++) {
    		int pos = t.find(b[i]);

    		if (pos == -1) {
    			continue;
    		}

    		int pos2 = pos;

    		for  (int k = (int) t.size() - 1; k >= 0; k --) {
    			if (t[k] == b[i]) {
    				pos2 = k;
    				break;
    			}
    		}

    		std::string t1 = t;

    		t1[pos] = b[j];

    		v1.push_back(t1);

    		t1[pos] = b[i], t1[pos2] = b[j];

    		v1.push_back(t1);
    	}
    }

    i64 ans = eval(t);

    for (auto &x: v1) {
    	ans = std::max(ans, eval(x));
    }

    std::cout << ans << "\n";
}

int main() {
    for (int i = 0, j = 1; i < 5; i ++, j *= 10) {
    	val['A' + i] = j;
    }
    int _ = nxt<int>();
    while (_ --) { solve(); }
}