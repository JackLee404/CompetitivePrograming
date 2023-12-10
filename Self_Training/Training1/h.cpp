#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;

int a[N], cnt, vis[N], dep[N];

/* 	很巧妙的一道题， 最终将
  问题转化为求： 从一个序列中任意挑出k个数，使其和为0，求最小的k
  这个问题再转化为bfs也很巧妙
  另外有个结论 对于 -k k 之间的数若存在一个前缀和序列为0那么调整一下，可以保证
  任意的前缀和0, k之间
*/

int bfs(){
	memset(dep, -1, sizeof dep);
	queue<int> q1;
	q1.push(0), dep[0] = 0;
	while(q1.size()) {
		int t = q1.front(); q1.pop();
		for(int i = 1; i <= cnt; i ++) {
			if(t + a[i] == 0){
				return dep[t] + 1;
			}
 			if(t + a[i] > 0 && t + a[i] <= 1000 && dep[t + a[i]] == -1) {
				q1.push(t + a[i]);
				dep[t + a[i]] = dep[t] + 1;
			}
		}
	}
	return -1;
}	

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i ++) {
		int t;
		cin >> t;
		if (!vis[t]) vis[t] = true, a[++cnt] = t - n;
	}
	cout << bfs();
}