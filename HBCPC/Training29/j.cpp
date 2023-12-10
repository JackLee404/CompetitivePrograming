#include <bits/stdc++.h>
#include <numeric>
using namespace std;

const int N = 1e4 + 10;

int n, k, m;

vector<vector<int>> a;

vector<float> ans;

int main() {
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++) {
		vector<int> b(k);
		for(auto &x: b) cin >> x;
		b.erase(max_element(b.begin(), b.end()));
		b.erase(min_element(b.begin(), b.end()));
		ans.push_back(accumulate(b.begin(), b.end(), 0) * 1.0 / (k - 2));
	}
	sort(ans.begin(), ans.end(), greater<int>());
    for(int i = m - 1; i >= 0; i --) {
	    printf("%.3f", ans[i]);
	    if(i != 0) cout << " ";
    }
}