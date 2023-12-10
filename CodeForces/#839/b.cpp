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
const int N = 1e5 + 10;

int a[3][3];

void rotate() {
   int b[3][3];
   memcpy(b, a, sizeof a);
   a[1][1] = b[2][1], a[1][2] = b[1][1];
   a[2][1] = b[2][2], a[2][2] = b[1][2]; 
}

bool check() {
    bool ck = true;
    rep (i, 1, 2) {
        if (a[i][1] > a[i][2]) ck = false;
    }
    rep (j, 1, 2) {
        if (a[1][j] > a[2][j]) ck = false;
    }
    return ck;
}

bool act() {
    if (check()) return true;
    rep (i, 1, 4) {
        rotate();
        if (check()) return true;
    }
    return false;
}


int main() {
    int _;
    cin >> _;
    while (_ --) {
        rep (i, 1, 2) {
            rep (j, 1, 2) {
                cin >> a[i][j];
            }
        }
        puts(act()?"YES":"NO");
    }
}