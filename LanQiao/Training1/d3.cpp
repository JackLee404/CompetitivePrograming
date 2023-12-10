#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 310, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
vector<int> level[N];
int c[M], cnt[N];
int ans = N;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs_level(int u, int depth, int father) {
    cnt[u] = 1;

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        cnt[u] += dfs_level(j, depth + 1, u);
        level[depth].push_back(i);
    }

    return cnt[u];
}

void dfs_draw(int j, int color)
{
    c[j] = color;
    for (int i = h[e[j]]; ~i; i = ne[i])
        if (i != (j ^ 1))   // i不是j的反向边
            dfs_draw(i, color);
}

void dfs(int u, int s)
{
    ans = min(ans, s);

    for (int i = 0; i < level[u].size(); i ++ )
    {
        int j = level[u][i];
        if (!c[j])
        {
            dfs_draw(j, 1);
            dfs(u + 1, s - cnt[e[j]]);
            dfs_draw(j, 0);
        }
    }
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs_level(1, 0, -1);
    dfs(0, n);

    cout << ans << endl;

    return 0;
}