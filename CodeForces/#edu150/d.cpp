#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

bool is_possible(int x, int y, int z) {
    if (x == z || y == z || x + y == z || abs(x - y) == z || gcd(x, y) == z) {
        return true;
    }

    if (x > y) {
        swap(x, y);
    }

    if (y == 0) {
        return false;
    }

    if (z % gcd(x, y) != 0) {
        return false;
    }

    return is_possible(y, x % y, z) || is_possible(y, x + y, z);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (is_possible(x, y, z)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
