#include <iostream>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    while ((l | l + 1) < r) {
        l = l | (l + 1);
    }
    cout << l;
}
