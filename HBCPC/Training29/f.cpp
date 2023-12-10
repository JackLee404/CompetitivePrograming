#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ev, od; cin >> n;
    ev = od = 0;
    for(int i = 1; i <= n; i ++) {
        int t; cin >> t;
        if (t % 2 == 0) ev ++;
        else od ++;
    }
    cout << od << " " << ev;
}