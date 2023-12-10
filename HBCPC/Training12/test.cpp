#include <iostream>

using namespace std;

void output(int x) {
	cout << x << endl;
}

int main() {
	int len;
	cin >> len;
	output(--len);
}