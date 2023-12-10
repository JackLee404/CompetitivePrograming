#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
	int v, w;
};

int n, m, cnt[300], dist[300], man[300], info[300], num[300];
int pre[300];
bool ck[300];
vector<string> arr;
string st, ed;
map<string, vector<edge>> v;
map<string, int> f;

void dijkstra(string s) {
	memset(dist, 0x3f, sizeof dist);

	for(int i = 0; i <= 200; i ++) cnt[i] = -INF, man[i] = -INF;

	dist[f[s]] = man[f[s]] = cnt[f[s]] = 0;
    num[f[s]] = 1;

	for(int i = 1; i <= n; i ++) {
		int u = -1;
		for(int j = 0; j < n; j ++) {
			if(!ck[j] && (u == -1 || dist[j] < dist[u]))
				u = j;
		}
		ck[u] = 1;
		for(auto x: v[arr[u]]) {
			int v = x.v, w = x.w;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				cnt[v] = cnt[u] + 1;
				man[v] = man[u] + info[v];
				pre[v] = u;
                num[v] += num[u];
			} else if(dist[v] == dist[u] + w) {
				if(cnt[v] < cnt[u] + 1) {
                    dist[v] = dist[u] + w;
                    cnt[v] = cnt[u] + 1;
                    man[v] = man[u] + info[v];
                    pre[v] = u;
                    num[v] += num[u];
				} else if(cnt[v] == cnt[u] + 1 && man[v] < man[u] + info[v]) {
                    dist[v] = dist[u] + w;
                    cnt[v] = cnt[u] + 1;
                    man[v] = man[u] + info[v];
                    pre[v] = u;
                    num[v] += num[u];
				}
			}
		}
	}
}

void out(int u) {
	if(u == 0) {
		cout << arr[u];
	} else {
		out(pre[u]);
		cout << "->" << arr[u];
	}
}


int main() {
	cin >> n >> m >> st >> ed;
// 	cout << n << m << st << ed << endl;
	arr.push_back(st);
	f[st] = 0;
	for(int i = 1; i <= n - 1; i ++) {
		string a;
		int b;
		cin >> a >> b;
		info[i] = b;
		f[a] = i;
		arr.push_back(a);
	}
	for(int i = 1; i <= m; i ++) {
		string a, b;
		int len;
		cin >> a >> b >> len;
		v[a].push_back({f[b], len});
		v[b].push_back({f[a], len});
	}
	dijkstra(st);
	out(f[ed]);
	puts("");
	cout << num[f[ed]] << " " << dist[f[ed]] << " " << man[f[ed]];
}