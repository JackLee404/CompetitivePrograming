#include <iostream>
#include <vector>
using namespace std;

const int N = 3e6;

int l, r, mx = -1, b[N];

struct trie{
	int nex[N][2], idx;
	bool exist[N];

	void insert(int x) {
		int p = 0;
		for (int i = 20; i >= 0; i --) {
			if (!nex[p][x>>i&1]) nex[p][x>>i&1] = ++idx;
			p = nex[p][x>>i&1];
		}
		exist[p] = 1;
	}

	int find(int x) {
		int p = 0, res = 0;
		for (int i = 20; i >= 0; i --) {
			if (!nex[p][!(x>>i&1)]) {
				p = nex[p][x>>i&1];
				if (x>>i&1) res += (1 << i);
			} 
			else {
				p = nex[p][!(x>>i&1)];
				if (!(x>>i&1)) res += (1<<i);
			} 
		}
		return res;
	}
};

int main() {
	trie tree;
	int n; cin >> n;
	vector<int> a(n + 1), pre(n + 1);
	tree.insert(0), b[0] = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
        
        pre[i] = pre[i - 1] ^ a[i];
        
        int res = tree.find(pre[i]);
        
		if((pre[i] ^ res) > mx) {
			l = b[res], r = i, mx = pre[i] ^ res;
		}
        
        b[pre[i]] = i + 1;
        tree.insert(pre[i]);
	}
	cout << mx << " " << l << " " << r;
}