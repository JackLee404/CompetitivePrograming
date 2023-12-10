#include <iostream>
#define xian puts("niuniu")
#define hou puts("niumei")
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t --) {
		long long a, b;
		cin >> a >> b;
		// 1,2  1,1 同样满足所以不考虑边界
        if(min(a - 1, b - 2) % 3 == 0 || min(a - 2, b - 1) % 3 == 0) xian;
        else hou;
	}
}