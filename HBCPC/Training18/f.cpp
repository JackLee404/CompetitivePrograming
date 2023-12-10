#include <iostream>

using namespace std;


string input(string a) {
	string s = "";
	for (int i = 1; i < a.size(); i++) {
	  if (a[i] % 2 == a[i-1] % 2) {
	    s += max(a[i], a[i-1]);
	  }
	}
	return s;
}

int main() {
	string a, b;
	if (input(a) == input(b)) {
		cout << input(a);
	} else {
		cout << input(a) << "\n" << input(b);
	}
}