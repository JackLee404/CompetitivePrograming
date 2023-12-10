#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
#define pb(x) push_back(x)
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
#define Inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10;
struct edge{int v, w;};
bool st[N], vis[N];
int dist[N], pre[N], n, m, s, cnt;
vector<edge> g[N];
priority_queue<pii> q;

void check(int s){
	for(auto &x: g[s]){
		if(vis[x.v]) continue;
		vis[x.v] = true;
		cnt ++;
		check(x.v);
	}
}

void dijkstra(int s){
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0, q.push({0, s});
	while (q.size()){
		auto t = q.top(); q.pop();
		int u = t.s;
		if (st[u]) continue;
		st[u] = 1;
		for (auto x : g[u]){
			int v = x.v, w= x.w;
			if (dist[v] > dist[u] + w){
				pre[v] = u;
				dist[v] = dist[u] + w;
				q.push({-dist[v], v});
			}
		}
	}
}
int main()
{
	cin >> n >> m >> s;
	rep(i, 1, m){
		int u, v;
		cin >> u  >> v;
		g[u].push_back({v, 1});
		g[v].push_back({u, 1});
	}
	cnt ++;
	vis[1] = true;
	check(1);
	int k;
	cin >> k;
	while(k --) {
		int t;
		cin >> t;
		if(cnt != n) cout << 0 << endl;
		dijkstra(t);
		int s1 = accumulate(dist + 1, dist + 1 + n, 0);
		printf("Cc(%d)=%.2f\n", t, (n - 1) * 1.0 / s1);
	}
}