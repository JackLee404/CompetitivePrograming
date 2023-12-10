#include <iostream>
using namespace std;
const int M = 1e9 + 7;

long long cal(long long x) {
	return x % M;
}

int main() {
	long long x;
    cin >> x;
    long long a1, a2;
    a1 = (x * (x + 1) * (2 * x + 1)) / 6;
    a2 = ((x * x) * (1 + x)) / 2;
    cout << cal(a2 - a1);
}