#include <bits/stdc++.h>
#include <cstring>

#define ff first
#define ss second

using i64 = long long;

const int N = 1e3;

struct node {
	int v, w;
};

std::vector<node> v1[N];

std::vector<int> v2;

int dist[N], pre[N], n, m, s, e, cnt, tot;
bool st[N];
int vip[N][N];

int g[N][N];

void add(int x, int y, int z) {
	v1[x].push_back({y, z});
	v1[y].push_back({x, z});
}

void dijkstra(int s){
	memset(dist, 0x3f, sizeof(dist));
    
    std::priority_queue<std::pair<int, int>> q;

	dist[s] = 0, q.push({0, s});

	while (q.size()){
		auto t = q.top(); q.pop();
		int u = t.ss;
		
		if (st[u]) continue;

		st[u] = 1;

		for (auto x : v1[u]){
			int  v = x.v, w = x.w;
			if (dist[v] > dist[u] + w){
				pre[v] = u;
				dist[v] = dist[u] + w;
				q.push({-dist[v], v});
			}
		}

	}
}

void out_path(int u) {
	if(u == s) {
		std::cout << s;
		return;
	}

	out_path(pre[u]);

	std::cout << " " << u;

	if(vip[pre[u]][u]) v2.push_back(vip[pre[u]][u]);
	tot += g[pre[u]][u];
}


int main() {

	std::cin >> n >> s >> e >> m;

	
	for(int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		add(x, y, z);

		g[x][y] = g[y][x] = z;
	}

	int k;

	std::cin >> k;

	while(k --) {
		int x, y, z;

		std::cin >> x >> y >> z;

		add(x, y, z);

		vip[x][y] = vip[y][x] = x;
		g[x][y] = g[y][x] = z;
	}

	dijkstra(s);


	out_path(e);
	

	puts("");

	// std::cout << pre[s];
	for(int i = 0; i < (int) v2.size(); i ++) {
		std::cout << v2[i] << " \n"[i == (int) v2.size() - 1];
	}

	if(!v2.size()) {
		std::cout << "Ticket Not Used";
	}
	
	puts("");
	
    
    std::cout << tot;
}