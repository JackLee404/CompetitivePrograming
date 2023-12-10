#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define f first
#define s second
#define pb(x) push_back(x)
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
#define Inf 0x3f3f3f3f
using namespace std;
const int N = 1e4 + 10;

vector<int> v1, v2;

int main() {
	int n; cin >> n;
	string t;
	while (n --) {
		int num;
		cin >> t;
		if (t == "Push") {
			cin >> num;
			v1.push_back(num);
			sort(v1.begin(), v1.end());
            v2.push_back(num);
		} else if(t == "Pop") {
			if (v2.size()) {
                cout << v2.back() << "\n";
                auto t = lower_bound(v1.begin(), v1.end(), v2.back());
                v1.erase(t);
                v2.pop_back();
            }
			else cout << "Invalid" << "\n";
		} else if(t == "PeekMedian") {
            int k = v1.size();
            if (!k) {
            	cout << "Invalid" << "\n";
            	continue;
            }
			if (v1.size() % 2 != 0) {
				cout << v1[(k + 1) / 2 - 1] << "\n";
			} else {
				cout << v1[k / 2 - 1] << "\n";
			}
		}
	}
}