#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e4 + 10;

/*
 2 1 3 4

 2 4 1 3 =>

 ->3 1 4 2


 1 2 4 3 =>

 ->1 2 3 4


 2 1 3 4 =>

 ->2 1 3 4

*/

struct trie {
  int nex[N][26], cnt;
  bool exist[N];  // 该结点结尾的字符串是否存在

  void insert(std::vector<int> &v, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = v[i];
      // std::cout << v[i] << "\n";
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p] = 1;
  }

  // bool find(char *s, int l) {  // 查找字符串
  //   int p = 0;
  //   for (int i = 0; i < l; i++) {
  //     int c = s[i] - '0';
  //     if (!nex[p][c]) return 0;
  //     p = nex[p][c];
  //   }
  //   return exist[p];
  // }

  int act(std::vector<int> &v, int l) {
  	int p = 0, ans = 0;
  	for(int i = 0; i < l; i ++) {
  		int c = v[i];
  		if(!nex[p][c]) return ans;
  		ans ++;
  	}
  	return ans;
  }
};

void solve() {
	trie tree;
	
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n);

	for(int i = 0; i < n; i ++) {
		v[i].resize(m);
		std::vector<int> t(m);
		for(int j = 0; j < m; j ++) {
			std::cin >> v[i][j];
			t[v[i][j]] = j;
		}
		tree.insert(t, m);
	}

	for(int i = 0; i < n; i ++) {
		// std::vector<int> v2(m);
		// for(int j = 0; j < m; j ++) {	
		// 	v2[v[i][j] - 1] = j + 1;
		// }
		std::cout << tree.act(v[i], m) << " \n"[i == n - 1];
	}

}

int main() {
	int _;
	std::cin >> _;
	while(_ --){
		solve();
	}
}