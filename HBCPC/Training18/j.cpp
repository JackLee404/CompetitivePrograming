#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
#define per(i, j, k) for (int i = j; i >= k; i --)
using namespace std;

map<string, string> mp;

const int N = 1e5 + 10;

struct node{
	string its, next;
};

bool cmp(node a, node b) {
	return a.its < b.its;
}


int main() {
	int n;
	cin >> n;
	vector<node> v1(n);
	for (auto &it: v1) {
		string c;
		cin >> it.its >> c >> it.next;
	}

	sort(v1.begin(), v1.end(), cmp);

	for (int i = 0; i < n; i ++) {
		if (i != n - 1) {
			if (v1[i].next != v1[i + 1].its) {
				cout << v1[i].next << " - " <<  v1[i + 1].its << endl;
			}
		}
	}
}