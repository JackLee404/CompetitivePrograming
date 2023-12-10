#include <iostream>

using namespace std;

const char out[] = {"duo chi yu!", "duo chi rou!", "wan mei!", "ni li hai!", "shao chi rou!"};

int main() {
	int a, b, c;
	if (a) {
		if (b<130) cout << out[0];
		else if (b == 130)cout << out[2];
		else cout << out[3];
		cout << " ";
		if (c < 27) cout << out[1];
		else if (c == 27) cout << out[2];
		else cout << out[4];
	} else {
		if (b<129) cout << out[0];
		else if (b == 129)cout << out[2];
		else cout << out[3];
		cout << " ";
		if (c < 25) cout << out[1];
		else if (c == 25) cout << out[2];
		else cout << out[4];
	}
}