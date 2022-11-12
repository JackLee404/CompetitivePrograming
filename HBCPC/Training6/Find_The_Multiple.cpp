#include<iostream>

using namespace std;
typedef long long LL;

int n, flag;

void dfs(unsigned long long a, int step) {
        if (flag)
                return;
        if (step == 19)
                return;
        if (a % n == 0) {
                cout << a << endl;
                flag = true;
                return;
        }
        dfs(a * 10, step + 1);
        dfs(a * 10 + 1, step + 1);
}

int main() {
        while (cin >> n && n) {
                flag = false;
                dfs(1, 0);
        }
}