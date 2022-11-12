#include <iostream>
#include <cctype>

char d1[] = {'a', 'e', 'i', 'o', 'u'};
using namespace std;

int main() {
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i ++) {
		for (int j = 0; j < 5; j ++) {
			if (a[i] == d1[j]) {
				a[i] = toupper(a[i]);
			}

		}
	}
	cout << a;
}