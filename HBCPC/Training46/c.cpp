#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) return false;

    for (int i = 2; i <= num / i; ++i) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    int n;

    cin >> n;

    vector<int> A(n);

    // 2p  p  odd even

    int ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0;


    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] == 2) ct1 ++;
        else if (is_prime(A[i])) ct2 ++;
        else if (A[i] % 2) ct3 ++;
        else ct4 ++;
    }

    if ((ct3 && ct3 % 2 && !ct2) || (ct4 && ct4 % 2 && !ct1)) {
        puts("No");
    } else {
        puts("Yes");
    }
}
