#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, cnt = 0;
	string loop = "ROYGBIV", ad = "GBIV";
	cin >> n;
	for (int i = 1; i <= n - 7; i ++) {
	    loop += ad[(i - 1) % 4];
	}
	cout << loop;
}


// R、O、Y、G、B、I、V, G, B, I, V, G,