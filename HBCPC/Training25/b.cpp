#include <iostream>

using namespace std;

int main(){
	int cnt = 0;
	char c;
	while (cin >> c) {
		if (c == '6') cnt ++;
		if (cnt && c != '6') {
			if (cnt < 3) printf(string(cnt, '6').c_str());
			else if (cnt < 9) printf("9");
			else printf("27");
			printf("%c", c);
			cnt = 0;
		}
	}
}