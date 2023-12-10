#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10, M = N * 2;

int n, m;

i64 h[N], e[M], ne[M], idx;

i64 depth[N], fa[N][21];

i64 en[N], b[N];

i64 d[N], w[M];

i64 q[N];

void add(int a, int b, int c) {
    ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

void bfs(int s) {
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[s] = 1;
    std::queue<int> q1;
    q1.push(s);
    d[s] = 0;

    while (q1.size()) {
        int t = q1.front(); q1.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (depth[v] > depth[t] + 1) {
                q1.push(v);
                d[v] = d[t] + w[i];
                depth[v] = depth[t] + 1;
                fa[v][0] = t;
                for (int k = 1; k <= 20; k ++) {
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) std::swap(a, b);

    for (int k = 20; k >= 0; k --) {
        if (depth[fa[a][k]] >= depth[b]) {
            a = fa[a][k];
        }
    }

    if (a == b) return a;

    for (int k = 20; k >= 0; k --) {
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    }

    return fa[a][0];
}

i64 get(int a, int b) {
    return d[a] + d[b] - 2 * d[lca(a, b)];
}

int main() {
    std::cin >> n >> m;

    int root = 0;

    memset(h, -1, sizeof h);

    for (int i = 1; i <= n - 1; i ++) {
        int a, b, c;

        std::cin >> a >> b >> c;


        add(a, b, c), add(b, a, c);

        en[b] ++;
    }

    for (int i = 1; i <= n; i ++) {
        if (!en[i]) root = i;
    }

    bfs(root);

    i64 sum = 0;

    for (int i = 1; i <= m; i ++) {
        std::cin >> b[i];
        if(i - 1) sum += get(b[i - 1], b[i]);
    }

    // std::cout << sum << "\n";


    for (int i = 1; i <= m; i ++) {
        i64 t = sum;
        
        if (i == 1) {
            t -= get(b[i], b[i + 1]);
        } else if(i == m) {
            t -= get(b[i - 1], b[i]);
        } else {
            t -= get(b[i - 1], b[i]) + get(b[i], b[i + 1]) - get(b[i - 1], b[i + 1]);
        }

        std::cout << t << " \n"[i == m];
    }
}