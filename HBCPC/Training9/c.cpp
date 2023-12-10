#include <iostream>
#include <map>

using namespace std;
int n, m;

bool st[100][100];

int main() {
	cin >> n >> m;
	if (n == m) {
		cout << 3 << endl;
	} else {
		cout << 2 << endl;
	}
}