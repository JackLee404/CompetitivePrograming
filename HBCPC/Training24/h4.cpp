#include <iostream>
#include <cstring>
#include <vector>
#define f first
#define s second
#define pb(x) push_back(x)
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
#define Inf 0x3f3f3f3f
using namespace std;
const int N = 1e4 + 10;
struct edge{int v, w;};
bool st[N];
int dist[N], pre[N], n, m, s;
vector<edge> g[N];
void dijkstra(int s){
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	rep (i, 1, n - 1){
		int u = 0;
		rep (j, 1, n)
			if (!st[j] && dist[j] < dist[u]) u = j;
		st[u] = 1; 
		for (auto x : g[u]){
			int v = x.v, w = x.w;
			if (dist[v] > dist[u] + w) {
				pre[v] = u;
				dist[v] = dist[u] + w;
			} else if (dist[v] ==  dist[u] + w) {
				
			}
		}
	}
}
void dfs_path(int u){
	if (u == 1){
		printf("%d", u);
	}
	dfs_path(pre[u]);
	printf("->%d", u);
}
int main(){
	cin >> n >> m >> s;
	rep(i, 1, m){
		int u, v, w;
		cin >> u  >> v >> w;
		g[u].push_back({v, w});
	}
	dijkstra(s);
	// rep (i, 1, n){
	// 	if (dist[i] == Inf) cout << (1<<31) - 1 << " ";
	// 	else cout << dist[i] << " ";
	// }
}