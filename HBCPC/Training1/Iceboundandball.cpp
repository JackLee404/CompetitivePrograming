#include <iostream>

typedef long long LL;

using namespace std;

LL q, n, p;

LL pow(LL a, LL b) {
  LL res = 1;
  while (b) {
    if (b & 1) res *= a;
    b >>= 1;
    a *= a % p;
    res %= p;
  }
  return res;
}


int main() {
  int _;
  cin >> _;
  while (_ --) {
    LL res;
    cin >> q >> n >> p;
    res = (pow(q, n + 1) - q) / (q - 1);
    cout << pow(q, n + 1) << endl;
    cout << res % p << endl;
  }
}
