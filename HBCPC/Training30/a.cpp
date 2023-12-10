#include <iostream>
#include <vector>
#include <cstring>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using namespace std;

const int N = 600;

int n, m;


int v1[N][N], v2[N][N], cnt[N];

void add(int a, int b, int len, int time){
	v1[a][b] = min(v1[a][b], len);
	v2[a][b] = min(v2[a][b], time);
}

int dist[N], tim[N], pre[N], pre2[N], s, ed;
vector<int> path1, path2;
bool st[N];

void dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[s] = 0;
	rep (i, 1, n - 1){
		int u = -1;
		rep(j, 0, n - 1)
			if(!st[j] && (u == -1 || dist[j] < dist[u])) 
				u = j;
		st[u] = 1;
		rep(i, 0, n - 1){
			if(dist[i] > dist[u] + v1[u][i]){
				dist[i] = dist[u] + v1[u][i];
				pre[i] = u;
				cnt[i] = cnt[u] + 1;
			} else if(dist[i] == dist[u] + v1[u][i]) {
				if(cnt[i] > cnt[u] + 1) {
					dist[i] = dist[u] + v1[u][i];
					pre[i] = u;
					cnt[i] = cnt[u] + 1;
				}
			}
		}
	}
}

void dijkstra2(){
	memset(tim, 0x3f, sizeof tim);
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	tim[s] = 0;
	rep (i, 1, n){
		int u = -1;
		rep (j, 0, n - 1)
			if (!st[j] && (u == -1 || tim[j] < tim[u]))
				u = j;
		st[u] = 1;
		rep(i, 0, n - 1) {
			if(tim[i] > tim[u] + v2[u][i]) {
				tim[i] = tim[u] + v2[u][i];
				pre2[i] = u;
				dist[i] = dist[u] + v1[u][i];
			} else if(tim[i] == tim[u] + v2[u][i]) {
				if(dist[i] > dist[u] + v1[u][i]) {
					tim[i] = tim[u] + v2[u][i];
					pre2[i] = u;
					dist[i] = dist[u] + v1[u][i];
				}
			}
		}
	}
}

void dfs_paths(int u){
	if (u == s){
		// printf("Distance = %d: %d", dist[ed], u);
		path1.push_back(s);
		return;
	}
	dfs_paths(pre[u]);
	// printf(" => %d", u);
	path1.push_back(u);
}

void dfs_paths2(int u){
	if (u == s){
		// printf("Time = %d: %d", tim[ed], u);
		path2.push_back(s);
		return;
	}
	dfs_paths2(pre2[u]);
	// printf(" => %d", u);
	path2.push_back(u);
}


void dfs_path(int u){
	if (u == s){
		printf("Distance = %d: %d", dist[ed], u);
		return;
	}
	dfs_path(pre[u]);
	printf(" => %d", u);
}

void dfs_path2(int u){
	if (u == s){
		printf("Time = %d: %d", tim[ed], u);
		return;
	}
	dfs_path2(pre2[u]);
	printf(" => %d", u);
}

int main() {
	memset(v1, 0x3f, sizeof v1);
	memset(v2, 0x3f, sizeof v2);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		add(a, b, d, e);
		if(!c) add(b, a, d, e);
	}
	cin >> s >> ed;
	dijkstra2();
	// cout << tim[ed] << endl;
	// cout << pre2[ed];
	dfs_paths2(ed);
	// puts("");
	dijkstra();
	// cout << dist[ed];
	dfs_paths(ed);
	if(path1.size() == path2.size()) {
		bool ok = true;
		for(int i = 0; i < path1.size(); i ++) {
			if(path1[i] != path2[i]) ok = false;
		}
		if(ok) {
			printf("Time = %d; Distance = %d: ", tim[ed], dist[ed]);	
			cout << path1[0];
			for(int i = 1; i < path1.size(); i ++) {
				cout << " => " << path1[i];
			}
			return 0;
		}
	}
    dfs_path2(ed);
    puts("");
	dfs_path(ed);
}