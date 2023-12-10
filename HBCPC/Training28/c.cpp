
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
struct edge{int v, w, cost;};
bool st[N];
int dist[N], pre[N], n, m, s, c[N];
vector<edge> g[N];


void dijkstra(int s){
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	rep (i, 1, n - 1){
		int u = 0;
		rep (j, 1, n)
			if (!st[j] && dist[j] < dist[u] && c[j] < c[u]) u = j;
		st[u] = 1; 
		for (auto x : g[u]){
			int v = x.v, w = x.w, cost = x.cost;
			if (dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
			} else if (dist[v] == dist[u] + w) {
				if(c[u] + c[w] < c[v]) {
					dist[v] = dist[u] + w;
					c[v] = c[u] + cost;
				}
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
int main()
{
	cin >> n >> m >> s;
	rep(i, 1, m){
		int u, v, w, cost;
		cin >> u  >> v >> w >> cost;
		g[u].push_back({v, w, cost});
	}
	dijkstra(s);
	cout << dist[s] << " " << c[s];
}