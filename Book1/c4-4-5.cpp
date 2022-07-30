#include <iostream>
#include <cstring>
#include <cstdio>
#define F(i, j, k) for (int i = j; i <= k; ++ i)
#define F1(i, j, k) for (int i = j; i >= k; -- i)
//#define LOCAL

const int maxn = 100, BIG = 1000;

using namespace std;

int r, c, n, q, d[maxn][maxn], d2[maxn][maxn], ans[maxn][maxn], col[maxn], kase = 0;

void copy(char type, int p, int q){
        if (type == 'R'){
                F(i, 1, c)
                        d[p][i] = d2[q][i];
        }
        else{
                F(i, 1, r)
                        d[i][p] = d2[i][q];
        }
}

void del(char type){
        memcpy(d2, d, sizeof(d));
        int cnt = type == 'R' ? r : c, cnt2 = 0;
        F(i, 1, cnt)
                if (!col[i]) copy(type, ++cnt2, i);
        type == 'R' ? r = cnt2 : c = cnt2;
}

void ins(char type){
        memcpy(d2, d, sizeof(d));
        int cnt = type == 'R' ? r : c, cnt2 = 0;
        F(i, 1, cnt){
                if (col[i]) copy(type, ++cnt2, 0);
                copy(type, ++cnt2, i);
        }
        type == 'R' ? r = cnt2 : c = cnt2;
}

int main(){
        #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        #endif
        memset(d, 0, sizeof(d));
        while (scanf("%d %d %d", &r, &c, &n) == 3 && r){
                F(i, 1, r)
                        F(j, 1, c)
                                d[i][j] = BIG * i + j;
                while (n --){
                        char cmd[10];
                        scanf("%s", cmd);
                        if (cmd[0] == 'E'){
                                int r1, c1, r2, c2;
                                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                                swap(d[r1][c1], d[r2][c2]);
                        }
                        else {
                                int a, x;
                                scanf("%d", &a);
                                memset(col, 0, sizeof(col));
                                F(i, 1, a) scanf("%d", &x), col[x] = 1;
                                if (cmd[0] == 'D') del(cmd[1]); else ins(cmd[1]);
                        }
                }
                memset(ans, 0, sizeof(ans));
                F(i, 1, r)
                        F(j, 1, c)
                                ans[d[i][j] / BIG][d[i][j] % BIG] = i * BIG + j;
                if (kase > 0) printf("\n");
                printf("Spreadsheet #%d\n", ++kase);
                scanf("%d", &q);
                while (q --){
                        int r1, c1;
                        scanf("%d%d", &r1, &c1);
                        printf("Cell data in (%d,%d) ", r1, c1);
                        if (ans[r1][c1] == 0) printf("GONE\n");
                        else printf("moved to (%d,%d)\n", ans[r1][c1] / BIG, ans[r1][c1] % BIG);
                }
        }
        return 0;
}
