#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


// int b_search(int x) {
// 	int l = 0, r = cnt;
// 	while (l < r) {
// 		int mid = l + r >> 1;
// 		if (primes[mid] >= x) r = mid;
// 		else r = mid + 1;
// 	}
// }

int main() {
	int _;
	cin >> _;
	get_primes(100000);
	while (_ --) {
		int n;
		cin >> n;
		for (int i = 0; i <= cnt; i ++) {
			if (n != primes[i] && st[primes[i] + n]) {
				cout << primes[i] << endl;
				break;
			}
		}
	}	
}