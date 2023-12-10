#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;

map<int, LL> mp;
vector<PII> v1;
LL s[N], sum;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		int c; cin >> c;
		mp[c] ++;
		sum += c;
	}

 	if (mp.size() == m) {
		cout << 0;
		return 0;
	}

	for (auto it: mp) v1.push_back(it);
	
	int k = v1.size();

	int p = -1;
	LL ans;

	for (int i = 0; i < v1.size(); i ++) {
		if (v1[(i + 1) % k].first != (v1[i].first + 1) % m) {
			p = i;
			s[p] = sum - v1[i].first * (LL) v1[i].second;
			break;
		}
	}


	if (p == -1) {
		cout << 0;
		return 0;
	}

	for (int i = p - 1; i >= 0; i --) {
		s[i] = s[(i + 1) % k] - v1[i].second * (LL) v1[i].first;
	}

	for (int i = (int) v1.size() - 1; i >= p + 1; i --) {
		if (v1[(i + 1) % k].first != (v1[i].first + 1) % m) {
			s[i] = sum - v1[i].first * (LL) v1[i].second;	
		} else {
			s[i] = s[(i + 1) % k] - v1[i].first * (LL) v1[i].second;
		}
	}


	// for(int i = 0; i < k; i++){
	//     int j = (p-i+k)%k;
	//     s[j] = sum;
	//     if(v1[(j+1)%k].first == (v1[j].first+1)%m) s[j] = s[(j+1)%k];
	//     s[j] -= v1[j].first * v1[j].second;
  	// }

	ans = s[0];

	for (int i = 0; i < v1.size(); i ++)  ans = min(ans, s[i]);

	cout << ans;
}