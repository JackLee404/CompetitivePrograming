#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

const int N = 2e5 + 10;

void solve() {
    long long n, tot; cin >> n;
    vector<int> a(n + 1), arr(2 * n, 0); tot = (n * (n + 1)) / 2;
    int curr = 0;
    arr[0] ++;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        curr ^= a[i];
        for (int k = 0; k * k < 2 * n; k ++) {
            if ((curr ^ (k * k)) < 2 * n) {
                tot -= arr[curr ^ (k * k)];
            }
        }
        arr[curr] ++;
    } 
    cout << tot << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_ --) {
        solve();
    }
}