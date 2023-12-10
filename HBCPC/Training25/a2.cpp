#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

vector<int> a;

LL cal(int x, int val) {
    LL ans = 0;
    int pos;
    for (pos = 31; pos >= 0 && !(val>>pos&1); pos --);
    // cout << pos << "\n";
    if (pos < 0) return x; 
    for (; pos >= 0; pos --) {
        if (!(val>>pos&1)) {
            if (ans + (1<<pos) > x) continue;
            ans += (1<<pos); 
        }
    }
    // cout << ans << "\n";
    return ans;
}

int main() {
    // int n, curr = 0; cin >> n;
    // a.resize(n + 1);
    // for (int i = 1; i <= n; i ++) cin >> a[i];
    // sort(a.begin() + 1, a.end(), greater<int>());
    // for (int i = 1; i <= n; i ++) {
    //     // cout << cal(a[i], curr) << "\n";
    //     curr ^= cal(a[i], curr);
    // }
    // cout << curr;
    cout << fixed << pow(2, 21);
}