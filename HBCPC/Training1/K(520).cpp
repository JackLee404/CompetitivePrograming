#include <iostream>
typedef long long LL; 
using namespace std;

const int M = 20180520;

int quick_pow(LL a, int b) {
    int ans = 1;
    while(b) {
       if(b & 1) ans = ans * a % M;
       b = b >> 1;
       a = a * a % M;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    printf("%d", quick_pow(2, n));
}
