#include <bits/stdc++.h>

using i64 = long long;

/*
	f[u][k] 表示以u为根的子树中路径为k的点对数量

	f[u][k] = f[u][k - w(u, v)]
*/