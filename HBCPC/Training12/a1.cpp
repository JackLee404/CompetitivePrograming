#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 15;


int main() {
	int n;
	cin >> n;
	bool check = true;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == 1) {
				if (check) {
					cout << 0;
				} else {
					cout << 1;
				}
			} else if (i == n) {
				if (check) {
					cout << 1;
				} else {
					cout << 0;
				}
				check = !check;
			} else {
				cout << j % 2;
			}
			if (j != n)
				cout << " ";
		}
		cout << endl;
	}
}