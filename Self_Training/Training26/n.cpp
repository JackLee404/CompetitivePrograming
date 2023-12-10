#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int N = 100010, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][17];
int d[N];//存储每个点差分数
int ans;

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
// 求lca
void bfs()
{
    memset(depth,0x3f,sizeof depth);
    queue<int> q;
    depth[0] = 0,depth[1] = 1;
    q.push(1);

    while(q.size())
    {
        int t = q.front();
        q.pop();
        for(int i = h[t];~i;i=ne[i])
        {
            int j = e[i];
            if(depth[j]>depth[t]+1)
            {
                depth[j] = depth[t]+1;
                q.push(j);
                fa[j][0] = t;
                //  +2^k-1      +2^k-1
                //  j → fa[j][k-1] → fa[j][k]
                for(int k = 1;k<=16;k++)
                {
                    fa[j][k] = fa[fa[j][k-1]][k-1];
                }
            }
        }
    }
}

int lca(int a, int b)
{
    // 从更低的a开始
    if (depth[a] < depth[b]) swap(a, b);
    // 把a和b提到同一个高度
    for (int k = 16; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    // 如果 a,b不是同一个点 两个一起往上跳
    for (int k = 16; k >= 0; k -- )
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    // lca 倍增最终停下来的位置是lca下一层 所以还要跳一步
    return fa[a][0];
}
// dfs 返回每一棵子树的和
int dfs(int u, int father)
{
    // 遍历以u为根节点的子树j的和 
    int res = d[u];
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            // 边t→j 砍掉后的方案 s
            int s = dfs(j, u);
            // 如果s=0 则随便砍
            if (s == 0) ans += m;
            // 如果s=1 则只能砍对应的非树边
            else if (s == 1) ans ++ ;
            // 子节点j的差分向上加给/传给 节点u
            res += s;
        }
    }
    // 如果没有子节点 即叶子节点 直接返回d[node]
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bfs();
    // 读入附加边==非树边
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        d[a] ++, d[b] ++, d[p] -= 2;
    }
    dfs(1, -1);
    printf("%d\n", ans);

    return 0;
}
