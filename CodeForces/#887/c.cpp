#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll j = 0, x = 1;
        while (k--) {
            while (j < n && a[j] <= x+j)
                j++;
            x += j;
        }

        cout << x << "\n";
    }
}