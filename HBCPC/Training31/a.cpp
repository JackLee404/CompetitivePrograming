#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int n, d, min_len = INF;

bool ok = false;

bool vis[200][200];

vector<pair<int, int>> v;
vector<pair<int, int>> reach;
vector<pair<int, int>> ans, curr;

inline double cal(int x1, int y1, int x2, int y2) {
    return sqrt(abs((x1 - x2) * (x1 - x2)) + abs((y1 - y2) * (y1 -y2))); 
}

bool check(int x, int y) {
    if(x <= 50 - d && x >= -50 + d) return true;
    if(y <= 50 - d && y >= -50 + d) return true;
    return false;
}

void dfs(int x, int y, double len) {
    if(check(x, y)) {
        if(!ok || (len < min_len)) {
            ans = curr;
            ok = true;
            min_len = len;
        } else if(ok && len == min_len && cal(0, 0, curr[0].first, curr[0].second) < cal(0, 0, ans[0].first, ans[0].second)) {
            ans = curr;
        }
    }
    for(auto &t: v) {
        if(vis[t.first][t.second]) continue;

        if(cal(x, y, t.first, t.second) <= d) {
            curr.push_back({t.first, t.second});
            vis[t.first][t.second] = true;
            dfs(t.first, t.second, len + cal(x, y, t.first, t.second));
            curr.pop_back();
            vis[t.first][t.second] = false;
       } 
    }
}

int main() {
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        if(cal(0, 0, x, y) <= d + 15) {
            reach.push_back({x, y});
        }
    }
    // cout << reach.size() << endl;
    // sort(reach.begin(), reach.end(), [](pair<int,int> &a, pair<int, int> &b){
    //     int k1 = cal(0, 0, a.first, a.second);
    //     int k2 = cal(0, 0, b.first, b.second);
    //     return k1 < k2;
    // });
    for(auto &t: reach) {
        memset(vis, 0, sizeof vis);
        curr.push_back({t.first, t.second});
        dfs(t.first, t.second, 0);
        curr.clear();
    }
    if(!ok) {
        cout << 0;
        return 0;
    }
    for(auto &x: ans) {
        cout << x.first << " " << x.second << endl;
    }
}