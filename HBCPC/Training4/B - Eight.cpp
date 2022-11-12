#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define IOS ios::sync_with_stdio(false);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define dbg1(a) cout << a << endl;
#define dbg2(a, b) cout << a << " " <<  b << endl;
#define dbg3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP;
typedef pair<string, int> PSI;
typedef pair<int, int> PII;
const int N = 1e6 + 10;

int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};
char act[] = {'l', 'u', 'd', 'r'};


unordered_map<string, int> d;
string ended = "12345678x";


struct node {
        int pre, dir;
        node(int PRE, int DIR) {
                pre = PRE, DIR = dir;
        }
        node(){}
}path[N];

void bfs() {
        int cnt = 0;
        queue<string> q1;
        q1.push(ended);
        path[cnt].pre = -1;
        path[cnt].dir = -1;
        d[ended] = cnt ++;
        while (q1.size()) {
                string t = q1.front(); q1.pop();
                int k = t.find('x');
                int x = k / 3, y = k % 3;
                rep (i, 0, 3) {
                        int tx = x + dx[i], ty = y + dy[i];
                        if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3) {
                                string b = t;
                                swap(b[k], b[tx * 3 + ty]);
                                if (d[b]) 
                                        continue;
                                q1.push(b);
                                path[cnt].pre = d[t];
                                path[cnt].dir = i;
                                d[b] = cnt++;
                        }
                }
        }
}



int main() {
        string start;
        char c;
        bfs();
        while (cin >> c) {
                start.clear();
                start += c;
                for (int i = 1; i < 9; i ++) {
                        cin >> c;
                        start += c;
                }
                if (!d[start]) {
                        puts("unsolvable");
                } else {
                        int k = d[start];
                        while (k != -1) {
                                printf("%c", act[path[k].dir]);
                                k = path[k].pre;
                        }
                        cout << endl;
                }
        }
}